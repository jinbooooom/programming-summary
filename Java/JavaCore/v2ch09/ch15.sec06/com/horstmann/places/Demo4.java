package com.horstmann.places;

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



public class Demo4 {
   public static void main(String[] args) {
      Country belgium = new Country("Belgium", 30510);

      JsonbConfig config = new JsonbConfig().withPropertyVisibilityStrategy(new PrivateVisibilityStrategy());
      Jsonb jsonb = JsonbBuilder.create(config);
      String json = jsonb.toJson(belgium);
      System.out.println(json);
   }
}
