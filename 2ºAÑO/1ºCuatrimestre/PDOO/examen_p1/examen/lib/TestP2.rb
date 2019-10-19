# encoding:utf-8

require_relative "dado.rb"
require_relative "tablero.rb"
require_relative "sorpresa.rb"
require_relative "estados_juego.rb"
require_relative "mazo_sorpresas.rb"
require_relative "diario.rb"
require_relative "titulo_propiedad.rb"
require_relative "civitas_juego.rb"
require_relative "agente_inmobiliario.rb"

module Civitas

  class TestP2
    def self.main
   
      casillas = Array.new
      casillas << Casilla.new_casilla_descanso("Parking")
      
            tablero = Civitas::Tablero.new(5)
      
      mazo = Civitas::Mazo_sorpresas.new()
      
        mazo.al_mazo(Civitas::Sorpresa.new_generico(Tipo_sorpresa::PAGARCOBRAR, -100, "Te han multado por ir a 10km/h con el coche TORTUGA"))
        mazo.al_mazo(Civitas::Sorpresa.new_generico(Tipo_sorpresa::PAGARCOBRAR,250,"Saludas a los autobuseros, por ser un buen ciudadano recibes 250 euros"))
        mazo.al_mazo(Civitas::Sorpresa.new_ir_casilla(Tipo_sorpresa::IRCASILLA, tablero, 4, "Te has caido en una alcantarilla y apareces en china, te mueves 4 casillas" ))
        mazo.al_mazo(Civitas::Sorpresa.new_ir_casilla(Tipo_sorpresa::IRCASILLA,tablero,2,"tropezar y no caerte es avanzar, te mueves dos casillas"))
        mazo.al_mazo(Civitas::Sorpresa.new_carcel(Tipo_sorpresa::IRCARCEL,tablero))
        mazo.al_mazo(Civitas::Sorpresa.new_generico(Tipo_sorpresa::PORCASAHOTEL,25,"Recibes dinero por pasar por tu territorio, toma 25" ))
        mazo.al_mazo(Civitas::Sorpresa.new_generico( Tipo_sorpresa::PORCASAHOTEL,-10,"No es tu territorio ahora pagas 10"))
        mazo.al_mazo(Civitas::Sorpresa.new_generico(Tipo_sorpresa::PORJUGADOR, -12, "le pagas al resto de jugadores 12"))
        mazo.al_mazo(Civitas::Sorpresa.new_generico(Tipo_sorpresa::PORJUGADOR, 12, "Hoy es el dia de la felicidad, todos los jugadores te dan 12"))
        mazo.al_mazo(Civitas::Sorpresa.new_salir_carcel(Tipo_sorpresa::SALIRCARCEL, mazo ))
      
      casillas << Casilla.new_casilla_descanso("Parking")
       casillas << Casilla.new_casilla_juez(5, "Juez")
       casillas << Casilla.new_casilla_impuesto(100, "Impuesto")
       casillas << Casilla.new_casilla_sorpresa(mazo, "Sorpresa 1")
       casillas << Casilla.new_casilla_sorpresa(mazo, "Sorpresa 2")
       casillas << Casilla.new_casilla_sorpresa(mazo, "Sorpresa 3")
       casillas << Casilla.new_casilla_calle(Civitas::Titulo_propiedad.new("C1", 150, 200, 80, 45, 140))
       casillas << Casilla.new_casilla_calle(Civitas::Titulo_propiedad.new("C2", 170, 250, 90, 55, 150))
       casillas << Casilla.new_casilla_calle(Civitas::Titulo_propiedad.new("C3", 190, 300, 100, 65, 160))
      casillas <<  Casilla.new_casilla_calle(Civitas::Titulo_propiedad.new("C4", 210, 350, 110, 75, 170))
       casillas << Casilla.new_casilla_calle(Civitas::Titulo_propiedad.new("C5", 230, 400, 120, 85, 180))
       casillas << Casilla.new_casilla_calle(Civitas::Titulo_propiedad.new("C6", 250, 450, 130, 95, 190))
       casillas << Casilla.new_casilla_calle(Civitas::Titulo_propiedad.new("C7", 270, 500, 140, 105, 200))
       casillas << Casilla.new_casilla_calle(Civitas::Titulo_propiedad.new("C8", 290, 550, 150, 115, 210))
       casillas << Casilla.new_casilla_calle(Civitas::Titulo_propiedad.new("C9", 310, 600, 160, 125, 220))
       casillas << Casilla.new_casilla_calle(Civitas::Titulo_propiedad.new("C10", 330, 650, 170, 135, 230))
       casillas << Casilla.new_casilla_calle(Civitas::Titulo_propiedad.new("C11", 350, 700, 180, 145, 240))
       casillas << Casilla.new_casilla_calle(Civitas::Titulo_propiedad.new("C12", 370, 750, 190, 155, 250))
      

      
      puts agente = PersonalDeApoyo::Agente_inmobiliario.new(14,casillas, "prueba")
      puts agente.nombre
      puts agente.nombre="hola"
      puts agente.nombre
      puts agente.max_casillas
      puts agente.num_agentes
      puts agente.gestionarCasillas
      
    end
  end
  TestP2.main
end