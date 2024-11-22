SELECT 
    a.nome_aluno,
    SUM(ie.quantidade) AS total_livros_emprestados
FROM Aluno a
INNER JOIN Emprestimo e ON a.id_aluno = e.id_aluno
INNER JOIN Itens_Emprestimo ie ON e.id_emprestimo = ie.id_emprestimo
GROUP BY a.nome_aluno
ORDER BY total_livros_emprestados DESC;

SELECT 
    status_multa,
    AVG(valor_multa) AS media_valor_multa
FROM Multa
GROUP BY status_multa;

SELECT 
    a.nome_aluno,
    COUNT(e.id_emprestimo) AS total_emprestimos
FROM Aluno a
INNER JOIN Emprestimo e ON a.id_aluno = e.id_aluno
GROUP BY a.nome_aluno
HAVING  COUNT(e.id_emprestimo) > 1;

SELECT 
    MAX(quantidade) AS "Maior quantidade de exemplares em um emprestimo",
    MIN(quantidade) AS "Menor quantidade de exemplares em um emprestimo"
FROM 
    Itens_Emprestimo;

SELECT 
    a.nome_aluno,
    SUM(m.valor_multa) AS total_multa
FROM Aluno a
INNER JOIN Emprestimo e ON a.id_aluno = e.id_aluno
INNER JOIN Multa m ON e.id_emprestimo = m.id_emprestimo
GROUP BY a.nome_aluno
HAVING SUM(m.valor_multa) > 5;
