package repository;

import model.programState.ProgramState;
import exceptions.ADTExceptions;

import java.util.List;
import java.io.IOException;
import java.util.List;

public interface IRepository {

    List<ProgramState> getProgramStates();
    void addProgram(ProgramState programState);
    ProgramState getCurrentState();
    void setProgramStates(List<ProgramState> programStates);
    void logPrgStateExec() throws IOException, ADTExceptions;
    void emptyLogFile() throws IOException;
    //void printToLogFile() throws ADTExceptions;

}
