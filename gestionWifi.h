  
  #ifndef GESTION_WIFI_H
  #define GESTION_WIFI_H
  
    
    #include <ESP8266WiFi.h>

    /* Variable de estado de la conexion del servidor */
    
    typedef enum {CONECTADO, NCONECTADO} tEstadoConexion;
    tEstadoConexion estadoConexion;
  
    // Redes WiFi guardadas para la conexion del ESP8266
    
    const char* ssid ="AETEL";
    const char* password = "nosetioalgoquemole";
    
    /* Cabeceras de las funciones */
    
    void setup_wifi();
    
    void estadoWifi();
  
  #endif
