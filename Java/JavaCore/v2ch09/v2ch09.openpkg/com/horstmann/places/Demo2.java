package com.horstmann.places;

//TODO: Put into v2ch09.openpkg2

/*
 
 javac -p javax.json.bind-api-1.0.jar \
    v2ch09.openpkg/module-info.java \
    v2ch09.openpkg/com/horstmann/places/Demo2.java \
    v2ch09.openpkg/com/horstmann/places/Country.java
 
 java -p javax.json-api-1.1.2.jar:javax.json-1.2-SNAPSHOT.jar:javax.json.bind-api-1.0.jar:yasson.jar:v2ch09.openpkg \
    -m v2ch09.openpkg/com.horstmann.places.Demo2
 
 */


import javax.json.bind.*;
import javax.json.bind.config.*;

import java.lang.reflect.*;

class PrivateVisibilityStrategy implements PropertyVisibilityStrategy {

    @Override
    public boolean isVisible(Field field) {
        return true;
    }

    @Override
    public boolean isVisible(Method method) {
        return false;
    }
}

public class Demo2 {
   public static void main(String[] args) {
      Country belgium = new Country("Belgium", 30510);

      JsonbConfig config = new JsonbConfig().withPropertyVisibilityStrategy(new PrivateVisibilityStrategy());
      Jsonb jsonb = JsonbBuilder.create(config);
      String json = jsonb.toJson(belgium);
      System.out.println(json);
   }
}
