  #ifndef HARDWARE_H
  #define HARDWARE_H
  
  #define pin_puerta  D1 // Pin del ESP8266 que vamos a usar para el PUERTA

    // Rele Puerta 
    #define ACTIVAR HIGH
    #define DESACTIVAR LOW


    /* Cabeceras de las funciones */
    
    void gestionPuerta();
    
    void inicializarPines();

  #endif
