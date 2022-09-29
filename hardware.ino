  #include "hardware.h"

  /* La funcion que se encuentra a continuacion, tiene una labor fundamental, ya que se encarga de instanciar todos los pines del ESP8266 que se van a usar durante 
       su funcionamiento, es decir, es donde asociamos cada elemento que compone el sistema (sensores, interruptores, actuadores, etc.) con un pin I/O del ESP8266 */
       
    void inicializarPines(){
        
      /*  COMPONENETES CONECTADOS  */
      
      pinMode(pin_puerta,OUTPUT);  // Configurar pin de la PUERTA como SALIDA
      
      digitalWrite(pin_puerta, DESACTIVAR); //Desactivar rele
     
    } // end INICIALIZAR_PINES()

    
    void gestionPuerta(){
      
      digitalWrite(pin_puerta, ACTIVAR);
      delay(5000);
      digitalWrite(pin_puerta, DESACTIVAR);
      
    } // end GESTIONPUERTA()
