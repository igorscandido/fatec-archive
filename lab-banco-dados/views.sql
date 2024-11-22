CREATE VIEW vw_emprestimos_ativos AS
SELECT 
    e.id_emprestimo,
    a.nome_aluno,
    a.matricula,
    l.titulo,
    ie.quantidade,
    e.data_emprestimo,
    e.data_devolucao
FROM Emprestimo e
INNER JOIN Aluno a ON e.id_aluno = a.id_aluno
INNER JOIN Itens_Emprestimo ie ON e.id_emprestimo = ie.id_emprestimo
INNER JOIN Livro l ON ie.id_livro = l.id_livro
WHERE e.data_retorno IS NULL;

CREATE VIEW vw_multas_pendentes AS
SELECT 
    a.nome_aluno,
    a.matricula,
    COUNT(m.id_multa) AS total_multas_pendentes,
    SUM(m.valor_multa) AS valor_total_multas
FROM Aluno a
INNER JOIN Emprestimo e ON a.id_aluno = e.id_aluno
INNER JOIN Multa m ON e.id_emprestimo = m.id_emprestimo
WHERE m.status_multa = 'Pendente'
GROUP BY a.nome_aluno, a.matricula;

