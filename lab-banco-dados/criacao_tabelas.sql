CREATE TABLE Autor (
    id_autor SERIAL PRIMARY KEY,
    nome_autor VARCHAR(100) NOT NULL
);

CREATE TABLE Categoria (
    id_categoria SERIAL PRIMARY KEY,
    nome_categoria VARCHAR(50) NOT NULL UNIQUE
);

CREATE TABLE Livro (
    id_livro SERIAL PRIMARY KEY,
    titulo VARCHAR(150) NOT NULL,
    ano_publicacao INT CHECK (ano_publicacao > 0),
    id_autor INT NOT NULL,
    id_categoria INT NOT NULL,
    quantidade_exemplares INT NOT NULL CHECK (quantidade_exemplares >= 0),
    FOREIGN KEY (id_autor) REFERENCES Autor (id_autor),
    FOREIGN KEY (id_categoria) REFERENCES Categoria (id_categoria)
);

CREATE TABLE Aluno (
    id_aluno SERIAL PRIMARY KEY,
    nome_aluno VARCHAR(100) NOT NULL,
    matricula VARCHAR(20) UNIQUE NOT NULL,
    turma VARCHAR(10) NOT NULL
);

CREATE TABLE Emprestimo (
    id_emprestimo SERIAL PRIMARY KEY,
    id_aluno INT NOT NULL,
    data_emprestimo DATE NOT NULL,
    data_devolucao DATE NOT NULL,
    data_retorno DATE,
    FOREIGN KEY (id_aluno) REFERENCES Aluno (id_aluno)
);

CREATE TABLE Itens_Emprestimo (
    id_item SERIAL PRIMARY KEY,
    id_emprestimo INT NOT NULL,
    id_livro INT NOT NULL,
    quantidade INT NOT NULL CHECK (quantidade > 0),
    FOREIGN KEY (id_emprestimo) REFERENCES Emprestimo (id_emprestimo),
    FOREIGN KEY (id_livro) REFERENCES Livro (id_livro)
);

CREATE TABLE Multa (
    id_multa SERIAL PRIMARY KEY,
    id_emprestimo INT NOT NULL,
    valor_multa DECIMAL(10, 2) NOT NULL CHECK (valor_multa >= 0),
    data_multa DATE NOT NULL,
    status_multa VARCHAR(20) NOT NULL CHECK (status_multa IN ('Pendente', 'Paga')),
    FOREIGN KEY (id_emprestimo) REFERENCES Emprestimo (id_emprestimo)
);
