import java.util.concurrent.Semaphore;

public class Semaforo {
    private static final int TAMANHO_BUFFER = 5; // Define o tamanho limite que cada thread vai ter para produzir/consumir
    private static int[] buffer = new int[TAMANHO_BUFFER]; // Cria o array de inteiros do tamanho do buffer

    // Semaforo que permite o controle se a thread pode ou não ser executada
    private static Semaphore mutex = new Semaphore(1);
    // Semafoto que determina se o buffer está cheio ou não
    private static Semaphore cheio = new Semaphore(0);
    // Semafoto que determina se o buffer está vazio ou não
    private static Semaphore vazio = new Semaphore(TAMANHO_BUFFER);

    static class Produtor implements Runnable {
        public void run() {
            for (int i = 0; i < 10; i++) {
                try {
                    vazio.acquire();
                    mutex.acquire();

                    int item = i + 1;
                    buffer[i % TAMANHO_BUFFER] = item;
                    System.out.println("Produzido: " + item);

                    mutex.release();
                    cheio.release();
                } catch (InterruptedException ex) {
                    ex.printStackTrace();
                }
            }
        }
    }

    static class Consumidor implements Runnable {
        public void run() {
            for (int i = 0; i < 10; i++) {
                try {
                    cheio.acquire();
                    mutex.acquire();

                    int item = buffer[i % TAMANHO_BUFFER];
                    System.out.println("Consumido: " + item);

                    mutex.release();
                    vazio.release();
                } catch (InterruptedException ex) {
                    ex.printStackTrace();
                }
            }
        }
    }

    public static void main(String[] args) {
        // Instancia uma thread do produtor
        Thread produtorThread = new Thread(new Produtor());
        // Instancia uma thread do consumidor
        Thread consumidorThread = new Thread(new Consumidor());

        // Inicia a thread do produtor
        produtorThread.start();
        // Inicia a thread do consumidor
        consumidorThread.start();
    }
}
