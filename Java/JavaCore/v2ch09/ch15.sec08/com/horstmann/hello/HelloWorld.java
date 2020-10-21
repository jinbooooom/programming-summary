package com.horstmann.hello;

import com.horstmann.greetsvc.GreeterService;
import java.util.Locale;
import java.util.ServiceLoader;

public class HelloWorld {
    public static void main(String[] args) {
        ServiceLoader<GreeterService> greeterLoader
            = ServiceLoader.load(GreeterService.class);
        GreeterService chosenGreeter = null;
        for (GreeterService greeter : greeterLoader) {
            if (args.length > 0 &&
                  greeter.getLocale().getLanguage().equals(args[0]))
               chosenGreeter = greeter;
        }
        if (chosenGreeter == null)
           System.out.println("No suitable greeter. Try with arg de or fr");
        else
           System.out.println(chosenGreeter.greet("Modular World"));
    }
}
