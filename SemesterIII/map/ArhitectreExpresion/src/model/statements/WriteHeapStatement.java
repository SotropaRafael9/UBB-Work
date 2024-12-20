package model.statements;

import exceptions.ADTExceptions;
import exceptions.StatementExecutionExceptions;
import exceptions.ExpressionEvaluationExceptions;
import model.adt.heap.MyIHeap;
import model.adt.dictionary.MyIDictionary;
import model.expression.IExpression;
import model.statements.IStatement;
import model.programState.ProgramState;
import model.type.RefType;
import model.type.Type;
import model.value.RefValue;
import model.value.Value;
public class WriteHeapStatement implements IStatement{
    private final String varName;
    private final IExpression expression;

    public WriteHeapStatement(String varName, IExpression expression) {
        this.varName = varName;
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState state) throws ADTExceptions, ExpressionEvaluationExceptions, StatementExecutionExceptions {

        MyIDictionary<String, Value> symTable = state.getSymTable();
        MyIHeap heap = state.getHeap();

        if (!symTable.containsKey(varName))
            throw new StatementExecutionExceptions(String.format("%s not present in the symTable", varName));
        Value value = symTable.lookUp(varName);

        if (!(value instanceof RefValue))
            throw new StatementExecutionExceptions(String.format("%s not of RefType", value));

        RefValue refValue = (RefValue) value;
        Value evaluated = expression.eval(symTable, heap);

        if (!evaluated.getType().equals(refValue.getLocationType()))
            throw new StatementExecutionExceptions(String.format("%s not of %s", evaluated, refValue.getLocationType()));

        heap.update(refValue.getAddress(), evaluated);
        state.setHeap(heap);

        return null;
    }

    @Override
    public IStatement deepCopy() {
        return new WriteHeapStatement(varName, expression.deepCopy());
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws StatementExecutionExceptions, ExpressionEvaluationExceptions, ADTExceptions {
        if (typeEnv.lookUp(varName).equals(new RefType(expression.typeCheck(typeEnv))))
            return typeEnv;
        else
            throw new StatementExecutionExceptions("WriteHeap: right hand side and left hand side have different types.");
    }
    @Override
    public String toString() {
        return String.format("WriteHeap(%s, %s)", varName, expression);
    }
}
