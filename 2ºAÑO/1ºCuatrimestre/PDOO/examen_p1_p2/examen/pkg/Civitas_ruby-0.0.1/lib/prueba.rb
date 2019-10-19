#encoding:utf-8

#22 minutos

require_relative 'Sorpresa'
require_relative 'TipoSorpresa'
require_relative 'Qytetet'

module Test

  class Examen

    @@MAX=10

    #Ejercicio 3
    @contador_global=0

    def self.contador_global
      @contador_global
    end

    def self.contador_global=(v)
      @contador_global=v
    end
    ###################

    def initialize(c)
      @contador=c
    end

    def self.constructor1(c)
      new(c)
    end

    def self.constructor2()
      new(0)
    end

    private_class_method :new

    #También se podría no hacer new privado y añadir solo constructor2

    attr_reader :contador

    def contabilizar
      @contador=[@contador+1,@@MAX].min
    end

    def principal
      contabilizar

      #Ejercicio 2
      mazo=Array.new
      mazo<<ModeloQytetet::Sorpresa.new("Te conviertes a especulador", 5000, ModeloQytetet::TipoSorpresa::CONVERTIRME)
      mazo<<ModeloQytetet::Sorpresa.new("Ganas saldo", 100, ModeloQytetet::TipoSorpresa::PAGARCOBRAR)
      mazo<<ModeloQytetet::Sorpresa.new("Vas a la casilla 6", 6, ModeloQytetet::TipoSorpresa::IRACASILLA)
      suma_coste=0
      mazo.each do |s|
        suma_coste+=s.valor
      end
      media=suma_coste.to_f/mazo.length
      puts "La media es "+media.to_s
      ###################

      #Ejercicio 3
      self.class.contador_global=self.class.contador_global+1
      ###################

      #Ejercicio 4
      puts "Les presento el juego:"
      ModeloQytetet::Qytetet.instance.inicializarJuego(["Alicia","Verónica"])
      puts ModeloQytetet::Qytetet.instance.to_s
      ###################

      puts "Contador de principal "+@contador.to_s
    end

  end
end

#Programa principal
instancia=Test::Examen.constructor1(9)
2.times {
  instancia.principal
}

#Probamos el contador global a nivel de clase
instancia2=Test::Examen.constructor2
instancia2.principal

puts "Ejecuciones globales: "+Test::Examen.contador_global.to_s