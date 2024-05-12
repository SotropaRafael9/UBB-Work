package model.statements;

import exceptions.ADTExceptions;
import exceptions.StatementExecutionExceptions;
import exceptions.ExpressionEvaluationExceptions;
import model.programState.ProgramState;
import model.expression.IExpression;
import model.value.Value;
import model.type.Type;
import model.adt.dictionary.MyIDictionary;
import model.adt.list.MyIList;
public class PrintStatement implements IStatement{
    IExpression expression;

    public PrintStatement(IExpression expression) {
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState state) throws ADTExceptions, ExpressionEvaluationExceptions, StatementExecutionExceptions {
        MyIList<Value> out = state.getOut();
        out.add(expression.eval(state.getSymTable(), state.getHeap()));
        return null;
    }
    @Override
    public IStatement deepCopy() {
        return new PrintStatement(expression.deepCopy());
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws StatementExecutionExceptions, ExpressionEvaluationExceptions, ADTExceptions {
        expression.typeCheck(typeEnv);
        return typeEnv;
    }


    @Override
    public String toString() {
        return String.format("Print(%s)", expression.toString());
    }
}
