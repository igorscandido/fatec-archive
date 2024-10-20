import java.util.Date;
import java.util.UUID;

interface Usuario {
    String getTipoUsuario();
    UUID getRegistro();
    String getEmail();
    String getNome();
}

class Aluno implements Usuario {
    private UUID registro;
    private String nome;
    private String email;
    private String senha;
    private Date dataCadastro;

    public Aluno(UUID registro, String nome, String email,
                 String senha, Date dataCadastro, Date dataAtualizacao, String tipoUsuario) {
        this.registro = registro;
        this.nome = nome;
        this.email = email;
        this.senha = senha;
        this.dataCadastro = dataCadastro;
        this.dataAtualizacao = dataAtualizacao;
        this.tipoUsuario = tipoUsuario;
    }

    private Date dataAtualizacao;
    private String tipoUsuario;

    public String getTipoUsuario() {
        return this.tipoUsuario;
    }

    public UUID getRegistro() {
        return this.registro;
    }

    public String getEmail() {
        return this.email;
    }
    public String getNome() {
        return this.nome;
    }
}

class Administrador implements Usuario {
    private UUID registro;
    private String nome;
    private String email;
    private String senha;

    public Administrador(UUID registro, String nome, String email,
                         String senha, Date dataCadastro, Date dataAtualizacao, String tipoUsuario) {
        this.registro = registro;
        this.nome = nome;
        this.email = email;
        this.senha = senha;
        this.dataCadastro = dataCadastro;
        this.dataAtualizacao = dataAtualizacao;
        this.tipoUsuario = tipoUsuario;
    }

    private Date dataCadastro;
    private Date dataAtualizacao;
    private String tipoUsuario;

    public String getTipoUsuario() {
        return this.tipoUsuario;
    }

    public UUID getRegistro() {
        return this.registro;
    }

    public String getEmail() {
        return this.email;
    }
    public String getNome() {
        return this.nome;
    }
}

interface UsuarioFactory {
    Usuario createUsuario();
}

class AlunoFactory implements UsuarioFactory {
    public Usuario createUsuario() {
        return new Aluno(
                UUID.randomUUID(),
                "João Silva",
                "joao.silva@example.com",
                "senhaSegura123",
                new Date(),
                new Date(),
                "Aluno"
        );
    }
}

class AdministradorFactory implements UsuarioFactory {
    public Administrador createUsuario() {
        return new Administrador(
                UUID.randomUUID(),
                "João Silva",
                "joao.silva@example.com",
                "senhaSegura123",
                new Date(),
                new Date(),
                "Admin"
        );
    }
}