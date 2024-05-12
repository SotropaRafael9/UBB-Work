package model.adt.list;

import exceptions.ADTExceptions;

import java.util.List;
public interface MyIList<T> {
    int size();
    boolean isEmpty();
    void add(T e);
    T get(int index);
    List<T> getList();
    String toString();
}
