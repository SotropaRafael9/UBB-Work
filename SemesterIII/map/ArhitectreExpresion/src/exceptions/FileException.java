package exceptions;

import java.io.File;

public class FileException extends Exception{
    public FileException(String message) {
        super(message);
    }
    public FileException(){super();}
}
