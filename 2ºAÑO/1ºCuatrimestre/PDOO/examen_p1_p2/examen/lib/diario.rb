# encoding:utf-8

require 'singleton'
module Civitas
  class Diario
    include Singleton

    def initialize
      @eventos = []
    end

    def ocurre_evento(e)
      @eventos << e
    end

    def eventos_pendientes
      return (@eventos.length > 0)
    end

    def leer_evento
      e = @eventos.shift
      return e
    end

  end
end

#MIRAR NOMBRES DE LOS ARCHIVOS PARA VER COMO ES EN RUBY