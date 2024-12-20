package model.statements;

import exceptions.ADTExceptions;
import exceptions.StatementExecutionExceptions;
import exceptions.ExpressionEvaluationExceptions;
import model.adt.dictionary.MyIDictionary;
import model.adt.heap.MyIHeap;
import model.expression.IExpression;
import model.programState.ProgramState;
import model.type.RefType;
import model.type.Type;
import model.value.RefValue;
import model.value.Value;
public class NewStatement implements IStatement{
    private final String varName;
    private final IExpression expression;

    public NewStatement(String varName, IExpression expression) {
        this.varName = varName;
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState state) throws ADTExceptions, ExpressionEvaluationExceptions, StatementExecutionExceptions {

        MyIDictionary<String, Value> symTable = state.getSymTable();
        MyIHeap heap = state.getHeap();
        if (!symTable.containsKey(varName))
            throw new StatementExecutionExceptions(String.format("%s not in symTable", varName));
        Value varValue = symTable.lookUp(varName);

        if (!(varValue.getType() instanceof RefType))
            throw new StatementExecutionExceptions(String.format("%s in not of RefType", varName));
        Value evaluated = expression.eval(symTable, heap);
        Type locationType = ((RefValue)varValue).getLocationType();
        if (!locationType.equals(evaluated.getType()))
            throw new StatementExecutionExceptions(String.format("%s not of %s", varName, evaluated.getType()));
        int newPosition = heap.add(evaluated);
        symTable.put(varName, new RefValue(newPosition, locationType));
        state.setSymTable(symTable);
        state.setHeap(heap);

        return null;
    }

    @Override
    public IStatement deepCopy() {
        return new NewStatement(varName, expression.deepCopy());
    }
    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws StatementExecutionExceptions, ExpressionEvaluationExceptions, ADTExceptions {
        Type typeVar = typeEnv.lookUp(varName);
        Type typeExp = expression.typeCheck(typeEnv);
        if (typeVar.equals(new RefType(typeExp)))
            return typeEnv;
        else
            throw new StatementExecutionExceptions("NEW stmt: right hand side and left hand side have different types");
    }


    @Override
    public String toString() {
        return String.format("New(%s, %s)", varName, expression);
    }
}
