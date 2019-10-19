# encoding:utf-8


  require_relative "casilla"
  require_relative "dado.rb"
  require_relative "diario.rb"
  
  require_relative "mazo_sorpresas.rb"
  require_relative "tablero.rb"
  require_relative "sorpresa.rb"
  require_relative "titulo_propiedad.rb"
  
  module PersonalDeApoyo
    class Agente_inmobiliario
      
      #@@num_agentes=0
      @descripcion_agente = "gestor de un conjunto de casillas"
      
      def initialize(valor,casillas,nombre)
        @casillas = Array.new
        @num_agentes=0
        @nombre = nombre
        @max_casillas
        @num_agentes+=@num_agentes+1
        
        @max_casillas = valor
        for i in(0..@max_casillas)
          @casillas << casillas[i]
        end
        
      end
      
      def self.new_nombre(valor,casillas,nombre)
        new(valor,casillas,nombre)
      end

      def self.new_otro(valor,casillas)
        new(valor,casillas,"agente_anonimo")
      end
      
      def gestionarCasillas
        valor = Civitas::Dado.instance.tirar
        
        if valor == 6
          puts "hoy no trabajo"
        else
          @casillas.each do |i|
            if i.tipo == Civitas::Tipo_casilla::CALLE
              puts i.to_s
            end
          end
        end
        Civitas::Diario.instance.ocurre_evento("el valor de la tirada ha sido " + valor.to_s)
      end
      
      #consultor para num_agentes
      #def self.num_agentes
       # @@num_agentes
      #end
      
      attr_reader :nombre, :max_casillas, :num_agentes
      attr_writer :nombre
      
    end
 
  end
  
#end

