# frozen_string_literal: true

class Nodo
  attr_accessor :siguiente
  attr_reader :item

  def initialize(item)
    @siguiente = nil
    @item = item
  end
end

class Lista
  def initialize
    @head = nil
    @tail = nil
  end

  def agregar(valor)
    if @head
      obtener_cola.siguiente = Nodo.new(valor)
    else
      @head = Nodo.new(valor)
    end
  end

  def agregar_despues_de(objetivo, valor)
    if head == objetivo
      temp = @head.siguiente
      @head.siguiente = Nodo.new(valor)
      @head.siguiente.siguiente = temp
    elsif tail == objetivo
      agregar(valor)
    else
      nodo = @head
      until nodo.item == objetivo
        return if nodo == @tail

        nodo = nodo.siguiente
      end
      temp = nodo.siguiente
      nodo.siguiente = Nodo.new(valor)
      nodo.siguiente.siguiente = temp
    end
  end

  def quitar(valor)
    @head = @head.siguiente if head == valor
    nodo = @head
    until nodo.siguiente.item == valor
      return if nodo == @tail

      nodo = nodo.siguiente
    end
      nodo.siguiente = nodo.siguiente.siguiente
  end

  def vacio?
    @head ? false : true
  end

  def vaciar
    @head = nil
  end

  def obtener_cola
    if vacio?
      @tail = @head
    else
      nodo = @head
      nodo = nodo.siguiente while nodo.siguiente != nil
      @tail = nodo
    end
  end

  def buscar(valor)
    return @head if head == valor
    return @tail if tail == valor

    nodo = @head
    while nodo != nil
      if nodo.item == valor
        break
      else
        nodo = nodo.siguiente
      end
    end
    nodo
  end

  def contiene(valor)
    buscar(valor) ? true : false
  end

  def head
    @head.item
  end

  def tail
    @tail.siguiente.item
  end

  def mostrar
    if vacio?
      puts 'Lista vacia'
      return
    end
    nodo = @head
    while nodo != nil
      print String(nodo.item) + " "
      nodo = nodo.siguiente
    end
  end
end
