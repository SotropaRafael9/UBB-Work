package model.programState;

import exceptions.ADTExceptions;
import exceptions.ExpressionEvaluationExceptions;
import exceptions.InterpreterException;
import exceptions.ExecutionException;
import exceptions.StatementExecutionExceptions;
import model.adt.dictionary.MyIDictionary;
import model.adt.list.MyIList;
import model.adt.stack.MyIStack;
import model.statements.IStatement;
import model.value.Value;
import model.adt.heap.MyIHeap;

import java.io.BufferedReader;
import java.util.List;

public class ProgramState {
    private MyIStack<IStatement> exeStack;
    private MyIDictionary<String, Value> symTable;
    private MyIList<Value> out;
    private MyIDictionary<String, BufferedReader> fileTable;
    private IStatement originalProgram;
    private MyIHeap heap;
    private int id;
    private static int lastId = 0;
    public MyIDictionary<String, BufferedReader> getFileTable() {
        return fileTable;
    }

    public void setFileTable(MyIDictionary<String, BufferedReader> fileTable) {
        this.fileTable = fileTable;
    }

    public ProgramState(MyIStack<IStatement> exeStack, MyIDictionary<String, Value> symTable, MyIList<Value> out, MyIDictionary<String, BufferedReader> fileTable,MyIHeap heap, IStatement originalProgram) {
        this.exeStack = exeStack;
        this.symTable = symTable;
        this.out = out;
        this.originalProgram = originalProgram;
        this.fileTable = fileTable;
        this.heap = heap;
        this.id = setId();
        if(originalProgram != null)
            this.exeStack.push(originalProgram);
    }
    public ProgramState(MyIStack<IStatement> stack, MyIDictionary<String,Value> symTable, MyIList<Value> out, MyIDictionary<String, BufferedReader> fileTable, MyIHeap heap) {
        this.exeStack = stack;
        this.symTable = symTable;
        this.out = out;
        this.fileTable = fileTable;
        this.heap = heap;
        this.id = setId();
    }
    public synchronized int setId() {
        lastId++;
        return lastId;
    }
    public boolean isNotCompleted() {
        return exeStack.isEmpty();
    }
    public MyIStack<IStatement> getExeStack() {
        return exeStack;
    }
    public MyIDictionary<String, Value> getSymTable() {
        return symTable;
    }

    public void setExeStack(MyIStack<IStatement> exeStack) {
        this.exeStack = exeStack;
    }




    public void setSymTable(MyIDictionary<String, Value> symTable) {
        this.symTable = symTable;
    }

    public MyIList<Value> getOut() {
        return out;
    }

    public void setOut(MyIList<Value> out) {
        this.out = out;
    }

    public IStatement getOriginalProgram() {
        return originalProgram;
    }

    public MyIHeap getHeap() {
        return heap;
    }
    public void setHeap(MyIHeap heap) {
        this.heap = heap;
    }

    public void setOriginalProgram(IStatement originalProgram) {
        this.originalProgram = originalProgram;
    }

    public String exeStackToString() {
        StringBuilder exeStackStringBuilder = new StringBuilder();
        List<IStatement> stack = exeStack.getReversed();
        for (IStatement statement: stack) {
            exeStackStringBuilder.append(statement.toString()).append("\n");
        }
        return exeStackStringBuilder.toString();
    }
    public ProgramState oneStep() throws InterpreterException, ExecutionException, StatementExecutionExceptions, ExpressionEvaluationExceptions, ADTExceptions {
        if (this.exeStack.isEmpty())
            throw new ExecutionException("stack is empty");
        IStatement currentStatement = exeStack.pop();
        return currentStatement.execute(this);

    }

    public String symTableToString() throws ADTExceptions {
        StringBuilder symTableStringBuilder = new StringBuilder();
        for (String key: symTable.keySet()) {
            symTableStringBuilder.append(String.format("%s -> %s\n", key, symTable.lookUp(key).toString()));
        }
        return symTableStringBuilder.toString();
    }

    public String outToString() {
        StringBuilder outStringBuilder = new StringBuilder();
        for (Value elem: out.getList()) {
            outStringBuilder.append(String.format("%s\n", elem.toString()));
        }
        return outStringBuilder.toString();
    }

    public String fileTableToString() {
        StringBuilder fileTableStringBuilder = new StringBuilder();
        for (String key: fileTable.keySet()) {
            fileTableStringBuilder.append(String.format("%s\n", key));
        }
        return fileTableStringBuilder.toString();
    }

    public String toString() {
        return "ID: " + id +"\n"+
                "Execution stack: \n" + exeStack.toString() +
                "\nSymbol table: \n" + symTable.toString() +
                "\nHeap: \n" +heap.toString()+
                "\nOutput list: \n" + out.toString() +
                "\nFile table: \n" + fileTable.toString();
    }

    public String programStateToString() throws ADTExceptions {
        return "ID: " + id +"\n"+
                "Execution stack: \n" + exeStackToString() +
                "Symbol table: \n" + symTableToString() +
                "Heap: \n" +heap.toString()+"\n"+


                "Output list: \n" + outToString() +
                "File table:\n" + fileTableToString();

    }
}
