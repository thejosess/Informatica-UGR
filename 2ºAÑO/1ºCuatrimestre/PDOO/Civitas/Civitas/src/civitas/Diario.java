package civitas;



import java.util.ArrayList;

public class Diario {
  static final private Diario instance = new Diario();
  
  private ArrayList<String> eventos;
  
  static public Diario getInstance() {
    return instance;
  }
  
  private Diario () {
    eventos = new ArrayList<>();
  }
  
  void ocurreEvento (String e) {
    eventos.add (e);
  }
  
  public boolean eventosPendientes () {
    return !eventos.isEmpty();
  }
  
  public String leerEvento () {
    String salida = "";
    if (!eventos.isEmpty()) {
      salida = eventos.remove(0);
    }
    return salida;
  }
}
