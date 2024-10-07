import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Random;

class Processo implements Runnable {
    private final int pid;
    private final int tempoExecucao;
    private String estado;

    public Processo(int pid, int tempoExecucao) {
        this.pid = pid;
        this.tempoExecucao = tempoExecucao;
        this.estado = "Pronto";
    }

    public int getPid() {
        return pid;
    }

    public String getEstado() {
        return estado;
    }

    @Override
    public void run() {
        mudarEstado("Executando");
        try {
            Thread.sleep(tempoExecucao);
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
        mudarEstado("Finalizado");
    }

    private void mudarEstado(String novoEstado) {
        System.out.println("Processo " + pid + ": " + estado + " -> " + novoEstado);
        estado = novoEstado;
    }
}

class Escalonador {
    private final Queue<Processo> filaProcessos;

    public Escalonador() {
        this.filaProcessos = new LinkedList<>();
    }

    public void adicionarProcesso(Processo processo) {
        filaProcessos.add(processo);
    }

    public void executar() {
        while (!filaProcessos.isEmpty()) {
            Processo processoAtual = filaProcessos.poll();
            Thread thread = new Thread(processoAtual);
            thread.start();
            try {
                thread.join();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }
}

public class SimuladorGerenciamentoProcessos {
    public static void main(String[] args) {
        Escalonador escalonador = new Escalonador();
        Random random = new Random();

        for (int i = 1; i <= 5; i++) {
            int tempoExecucao = random.nextInt(1000) + 500;
            Processo processo = new Processo(i, tempoExecucao);
            escalonador.adicionarProcesso(processo);
        }

        escalonador.executar();
        
        System.out.println("Todos os processos foram finalizados.");
    }
}

