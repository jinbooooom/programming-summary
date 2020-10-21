@SuppressWarnings("module")
module ch15.sec06 {
   // requires java.xml.bind;
   // opens com.horstmann.places to java.xml.bind;
   // requires com.google.gson;
   // requires com.horstmann.util;
   // opens com.horstmann.places to com.horstmann.util;
   requires java.json.bind;
   opens com.horstmann.places to org.eclipse.yasson;
}
