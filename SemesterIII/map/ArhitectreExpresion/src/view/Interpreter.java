package view;
import exceptions.ExpressionEvaluationExceptions;
import exceptions.StatementExecutionExceptions;
import exceptions.ADTExceptions;
import controller.Controller;
import model.adt.dictionary.MyDictionary;
import model.adt.heap.MyHeap;
import model.adt.list.MyList;
import model.adt.stack.MyStack;
import model.expression.*;
import model.programState.ProgramState;
import model.statements.*;
import model.type.BoolType;
import model.type.IntType;
import model.type.RefType;
import model.adt.heap.MyIHeap;
import model.type.StringType;
import model.value.BoolValue;
import model.value.IntValue;
import model.value.StringValue;
import model.value.Value;
import repository.IRepository;
import repository.Repository;

import java.awt.*;
import java.io.IOException;


public class Interpreter {
    public static void main(String[] args) {
        TextMenu menu = new TextMenu();
        menu.addCommand(new ExitCommand("0", "exit"));
        IStatement ex12 = new CompoundStatement
                (

                        new VariableDeclarationStatement("a", new RefType(new BoolType())),
                        new CompoundStatement
                                (
                                        new VariableDeclarationStatement("counter", new IntType()),
                                        new WhileStatement
                                                (
                                                        new RelationalExpression("<", new VariableExpression("counter"), new ValueExpression(new IntValue(10))),
                                                        new CompoundStatement
                                                                (
                                                                        new ForkStatement
                                                                                (
                                                                                        new ForkStatement
                                                                                                (
                                                                                                        new CompoundStatement
                                                                                                                (
                                                                                                                        new NewStatement("a", new VariableExpression("counter")),
                                                                                                                        new PrintStatement(new ReadHeapExpression(new VariableExpression("a")))
                                                                                                                )
                                                                                                )
                                                                                ),

                                                                        new AssignStatement("counter", new ArithmeticExpression('+', new VariableExpression("counter"), new ValueExpression(new IntValue(1))))


                                                                )
                                                )


                                )
                );
        //try {
            //ex12.typeCheck(new MyDictionary<>());
            ProgramState prg12 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex12);
            IRepository repo12 = new Repository(prg12, "C:\\Users\\Rafael\\Desktop\\Ubb year 1\\HomeWorks\\Semester III\\map\\ArhitectreExpresion\\src\\text12.txt");
            Controller controller12 = new Controller(repo12);
            menu.addCommand(new RunExampleCommand("1", ex12.toString(), controller12));
        //} catch (ExpressionEvaluationExceptions | ADTExceptions | StatementExecutionExceptions e) {
            //System.out.println(e.getMessage());
            //}

            IStatement ex11 = new CompoundStatement
                    (
                            new VariableDeclarationStatement("v", new IntType()),
                            new CompoundStatement
                                    (
                                            new VariableDeclarationStatement("a", new RefType(new IntType())),
                                            new CompoundStatement
                                                    (
                                                            new AssignStatement("v", new ValueExpression(new IntValue(10))),
                                                            new CompoundStatement
                                                                    (
                                                                            new NewStatement("a", new ValueExpression(new IntValue(22))),
                                                                            new CompoundStatement
                                                                                    (
                                                                                            new ForkStatement
                                                                                                    (
                                                                                                            new CompoundStatement
                                                                                                                    (
                                                                                                                            new WriteHeapStatement("a", new ValueExpression(new IntValue(30))),
                                                                                                                            new CompoundStatement
                                                                                                                                    (
                                                                                                                                            new AssignStatement("v", new ValueExpression(new IntValue(32))),
                                                                                                                                            new CompoundStatement
                                                                                                                                                    (
                                                                                                                                                            new PrintStatement(new VariableExpression("v")),
                                                                                                                                                            new PrintStatement(new ReadHeapExpression(new VariableExpression("a")))
                                                                                                                                                    )
                                                                                                                                    )
                                                                                                                    )
                                                                                                    ),
                                                                                            new CompoundStatement
                                                                                                    (
                                                                                                            new PrintStatement(new VariableExpression("v")),
                                                                                                            new PrintStatement(new ReadHeapExpression(new VariableExpression("a")))
                                                                                                    )
                                                                                    )
                                                                    )
                                                    )
                                    )
                    );
            ProgramState prg11 = new ProgramState(
                    new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex11
            );
            IRepository repo11 = new Repository(
                    prg11, "C:\\Users\\Rafael\\Desktop\\Ubb year 1\\HomeWorks\\Semester III\\map\\ArhitectreExpresion\\src\\text11.txt");
            Controller controller11 = new Controller(repo11);


            IStatement ex10 = new CompoundStatement
                    (
                            new VariableDeclarationStatement("v", new RefType(new IntType())),
                            new CompoundStatement
                                    (
                                            new NewStatement("v", new ValueExpression(new IntValue(0))),
                                            new CompoundStatement
                                                    (
                                                            new VariableDeclarationStatement("a", new RefType(new RefType(new IntType()))),
                                                            new CompoundStatement
                                                                    (
                                                                            new NewStatement("a", new VariableExpression("v")),
                                                                            new CompoundStatement
                                                                                    (
                                                                                            new WriteHeapStatement("v", new ValueExpression(new IntValue(30))),
                                                                                            new CompoundStatement
                                                                                                    (
                                                                                                            new PrintStatement(new ReadHeapExpression(new ReadHeapExpression(new VariableExpression("a")))),
                                                                                                            new NewStatement("v", new ValueExpression(new IntValue(90)))))))));
            ProgramState prg10 = new ProgramState(
                    new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex10
            );
            IRepository repo10 = new Repository(
                    prg10, "C:\\Users\\Rafael\\Desktop\\Ubb year 1\\HomeWorks\\Semester III\\map\\ArhitectreExpresion\\src\\text10.txt");
            Controller controller10 = new Controller(repo10);

            IStatement ex1 = new CompoundStatement(
                    new VariableDeclarationStatement(
                            "v", new IntType()
                    ),
                    new CompoundStatement(
                            new AssignStatement(
                                    "v", new ValueExpression(new IntValue(2))),
                            new PrintStatement(new VariableExpression("v"))
                    )
            );
            ProgramState prg1 = new ProgramState(
                    new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex1
            );
            IRepository repo1 = new Repository(
                    prg1, "C:\\Users\\Rafael\\Desktop\\Ubb year 1\\HomeWorks\\Semester III\\map\\ArhitectreExpresion\\src\\log1.txt");
            Controller controller1 = new Controller(repo1);

            IStatement ex2 = new CompoundStatement(
                    new VariableDeclarationStatement("a", new IntType()),
                    new CompoundStatement(
                            new VariableDeclarationStatement("b", new IntType()),
                            new CompoundStatement(
                                    new AssignStatement(
                                            "a", new ArithmeticExpression(
                                            '+', new ValueExpression(
                                            new IntValue(2)
                                    ),
                                            new ArithmeticExpression(
                                                    '*', new ValueExpression(
                                                    new IntValue(3)
                                            ), new ValueExpression(new IntValue(5))))),
                                    new CompoundStatement(
                                            new AssignStatement(
                                                    "b", new ArithmeticExpression(
                                                    '+', new VariableExpression("a"),
                                                    new ValueExpression(new IntValue(1))
                                            )
                                            ),
                                            new PrintStatement(
                                                    new VariableExpression("b"))))));
            ProgramState prg2 = new ProgramState(
                    new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex2);
            IRepository repo2 = new Repository(
                    prg2, "C:\\Users\\Rafael\\Desktop\\map\\ArhitectreExpresion\\src\\log2.txt");
            Controller controller2 = new Controller(repo2);

            IStatement ex3 = new CompoundStatement(
                    new VariableDeclarationStatement("a", new BoolType()),
                    new CompoundStatement(
                            new VariableDeclarationStatement("v", new IntType()),
                            new CompoundStatement(
                                    new AssignStatement(
                                            "a", new ValueExpression(new BoolValue(true))),
                                    new CompoundStatement(new IfStatement(new VariableExpression("a"),
                                            new AssignStatement("v", new ValueExpression(new IntValue(2))),
                                            new AssignStatement("v", new ValueExpression(new IntValue(3)))),
                                            new PrintStatement(new VariableExpression("v"))))));
            ProgramState prg3 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex3);
            IRepository repo3 = new Repository(prg3, "C:\\Users\\Rafael\\Desktop\\map\\ArhitectreExpresion\\src\\log3.txt");
            Controller controller3 = new Controller(repo3);

            IStatement ex4 = new CompoundStatement(new VariableDeclarationStatement("varf", new StringType()),
                    new CompoundStatement(new AssignStatement("varf", new ValueExpression(new StringValue("C:\\Users\\Rafael\\Desktop\\map\\ArhitectreExpresion\\src\\test.txt"))),
                            new CompoundStatement(new VariableDeclarationStatement("vars", new StringType()),
                                    new CompoundStatement(new AssignStatement("vars", new ValueExpression(new StringValue("C:\\Users\\Rafael\\Desktop\\map\\ArhitectreExpresion\\src\\test2.txt"))), new CompoundStatement(new PrintStatement((new VariableExpression("varf"))),
                                            new CompoundStatement(new OpenReadFile(new VariableExpression("varf")),
                                                    new CompoundStatement(new OpenReadFile(new VariableExpression("vars")),
                                                            new CompoundStatement(new VariableDeclarationStatement("varc", new IntType()),
                                                                    new CompoundStatement(new ReadFile(new VariableExpression("varf"), "varc"),
                                                                            new CompoundStatement(new PrintStatement(new VariableExpression("varc")),
                                                                                    new CompoundStatement(new ReadFile(new VariableExpression("varf"), "varc"),
                                                                                            new CompoundStatement(new PrintStatement(new VariableExpression("varc")),
                                                                                                    new CloseReadFile(new VariableExpression("varf"))))))))))))));

            ProgramState prg4 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex4);
            IRepository repo4 = new Repository(prg4, "C:\\Users\\Rafael\\Desktop\\map\\ArhitectreExpresion\\src\\log4.txt");
            Controller controller4 = new Controller(repo4);

            IStatement ex5 = new CompoundStatement(new VariableDeclarationStatement("a", new IntType()),
                    new CompoundStatement(new VariableDeclarationStatement("b", new IntType()),
                            new CompoundStatement(new AssignStatement("a", new ValueExpression(new IntValue(5))),
                                    new CompoundStatement(new AssignStatement("b", new ValueExpression(new IntValue(7))),
                                            new IfStatement(new RelationalExpression(">", new VariableExpression("a"),
                                                    new VariableExpression("b")), new PrintStatement(new VariableExpression("a")),
                                                    new PrintStatement(new VariableExpression("b")))))));

            ProgramState prg5 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex5);
            IRepository repo5 = new Repository(prg5, "C:\\Users\\Rafael\\Desktop\\map\\ArhitectreExpresion\\src\\log5.txt");
            Controller controller5 = new Controller(repo5);

//        TextMenu menu = new TextMenu();
//        menu.addCommand(new ExitCommand("0", "exit"));
//        menu.addCommand(new RunExampleCommand("1", ex1.toString(), controller1));
//        menu.addCommand(new RunExampleCommand("2", ex2.toString(), controller2));
//        menu.addCommand(new RunExampleCommand("3", ex3.toString(), controller3));
//        menu.addCommand(new RunExampleCommand("4", ex4.toString(), controller4));
//        menu.addCommand(new RunExampleCommand("5", ex5.toString(), controller5));
//        menu.addCommand(new RunExampleCommand("6", ex10.toString(), controller10));
//        menu.addCommand(new RunExampleCommand("7", ex11.toString(), controller11));
//        menu.addCommand(new RunExampleCommand("8", ex12.toString(), controller12));
            menu.show();

    }
}
