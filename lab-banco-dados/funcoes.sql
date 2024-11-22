CREATE OR REPLACE FUNCTION calcular_multa_total_aluno(id_aluno_param INT)
RETURNS DECIMAL(10, 2) AS 
$$
DECLARE
    total_multa DECIMAL(10, 2);
BEGIN
    SELECT 
        COALESCE(SUM(m.valor_multa), 0) INTO total_multa
    FROM Multa m
    INNER JOIN Emprestimo e ON m.id_emprestimo = e.id_emprestimo
    WHERE e.id_aluno = id_aluno_param AND m.status_multa = 'Pendente';
    
    RETURN total_multa;
END;
$$
LANGUAGE plpgsql;

SELECT 
    a.*, 
    calcular_multa_total_aluno(a.id_aluno) AS multa_total 
FROM Aluno a;

CREATE OR REPLACE FUNCTION verificar_disponibilidade_livro(id_livro_param INT)
RETURNS BOOLEAN AS
$$
DECLARE
    exemplares_disponiveis INT;
BEGIN
    SELECT 
        quantidade_exemplares - COALESCE(SUM(ie.quantidade), 0) INTO exemplares_disponiveis
    FROM Livro l
    LEFT JOIN Itens_Emprestimo ie ON l.id_livro = ie.id_livro
    LEFT JOIN Emprestimo e ON ie.id_emprestimo = e.id_emprestimo AND e.data_retorno IS NULL
    WHERE l.id_livro = id_livro_param
    GROUP BY l.id_livro, l.quantidade_exemplares;

    RETURN exemplares_disponiveis > 0;
END;
$$
LANGUAGE plpgsql;

SELECT 
    l.*, 
    verificar_disponibilidade_livro(l.id_livro) AS livro_disponivel 
FROM Livro l;

CREATE OR REPLACE FUNCTION verificar_limite_emprestimos(id_aluno_input INT)
RETURNS BOOLEAN AS
$$
DECLARE
    emprestimos_ativos INT;
BEGIN
    SELECT COUNT(*) INTO emprestimos_ativos
    FROM Emprestimo
    WHERE id_aluno = id_aluno_input
    AND data_retorno IS NULL;

    IF emprestimos_ativos >= 3 THEN
        RETURN FALSE; -- Retorna falso se o aluno já tiver 3 empréstimos simultâneos
    ELSE
        RETURN TRUE; -- Retorna verdadeiro se o aluno puder fazer um novo empréstimo
    END IF;
END;
$$
LANGUAGE plpgsql;

SELECT a.*,
    verificar_limite_emprestimos(a.id_aluno)
FROM Aluno;

CREATE OR REPLACE FUNCTION calcular_data_devolucao_padrao(data_emprestimo DATE)
RETURNS DATE AS
$$
BEGIN
    RETURN data_emprestimo + INTERVAL '14 days';
END;
$$
LANGUAGE plpgsql;

SELECT calcular_data_devolucao_padrao(CURRENT_DATE);


