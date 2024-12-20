package model.adt.heap;

import exceptions.ADTExceptions;
import model.value.Value;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class MyHeap implements MyIHeap{
    Map<Integer, Value> heap;
    Integer freeLocationValue;

    public MyHeap() {
        this.heap = new HashMap<>();
        this.freeLocationValue = 1;
    }

    public int newValue(){
        freeLocationValue = 1;
        while(heap.containsKey(freeLocationValue))
            freeLocationValue += 1;
        return freeLocationValue;
    }

    @Override
    public int getFreeValue() {
        return freeLocationValue;
    }

    @Override
    public Map<Integer, Value> getContent() {
        return heap;
    }

    @Override
    public void setHeap(Map<Integer, Value> newHeap) {
        this.heap = newHeap;
    }

    @Override
    public int add(Value value) {
        freeLocationValue = newValue();
        heap.put(freeLocationValue, value);
        return freeLocationValue;
    }

    @Override
    public void update(Integer position, Value value) throws ADTExceptions {
        if(!heap.containsKey(position))
            throw new ADTExceptions(String.format("%d is not present in the heap", position));
        heap.put(position, value);
    }

    @Override
    public Value get(Integer position) throws ADTExceptions {
        if(!heap.containsKey(position))
            throw new ADTExceptions(String.format("%d is not present in the heap", position));
        return heap.get(position);
    }

    @Override
    public boolean containsKey(Integer position) {
        return this.heap.containsKey(position);
    }

    @Override
    public void remove(Integer key) throws ADTExceptions {
        if (!containsKey(key))
            throw new ADTExceptions(key + " is not defined.");
        freeLocationValue = key;
        this.heap.remove(key);
    }

    @Override
    public Set<Integer> keySet() {
        return heap.keySet();
    }

    @Override
    public String toString(){
        return this.heap.toString();
    }
}
