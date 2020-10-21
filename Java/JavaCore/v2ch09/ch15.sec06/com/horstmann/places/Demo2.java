package com.horstmann.places;

import com.google.gson.*;
   
public class Demo2 {
   public static void main(String[] args) {
      Country belgium = new Country("Belgium", 30510);
      Gson gson = new Gson();
      String json = gson.toJson(belgium);
      System.out.println(json);
      Object obj = gson.fromJson(json, Country.class);
      System.out.println(obj);
   }
}
