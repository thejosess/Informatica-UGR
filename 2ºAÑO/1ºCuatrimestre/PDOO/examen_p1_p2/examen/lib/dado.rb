# encoding:utf-8

require 'singleton'
module Civitas
  class Dado
    include Singleton
    
    @@SalidaCarcel = 5
    
    def initialize
      @random = Random.new
      @ultimo_resultado = 0
      @debug = false
    end
    #este constructor es privado??
        
    def tirar
      if !@debug
        @ultimo_resultado = @random.rand(5) + 1
      else
        @ultimo_resultado = 1
      end
      return @ultimo_resultado
    end
    
    def salgo_de_la_carcel
      valor = tirar
      puts "ha salido el numero #{valor}"
      if valor >=5
        return true
      else
        return false
      end
    end
    
    def quien_empieza(n)
      return rand(n)
    end
    
    def debug=(d)
      @debug = d
    end
    
    def get_ultimo_resultado
      return @ultimo_resultado
    end  
    
  end
end