import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Enumeration;
import java.util.List;
import java.util.jar.JarEntry;
import java.util.jar.JarFile;


public class LoadStress {
    public static final String EXTENSION_DIRECTORY = "java.ext.dirs";
    public static final String JAR_EXTENSION = ".jar";
    public static final String CLASS_EXTENSION = ".class";
    public static final String LANG_LIBRARY = "java.lang";

    public int loadedClasses;

    public LoadStress() {
        loadedClasses = 0;
    }

    public void loadClasses() {
        String [] allExtensionDirectories = System.getProperty(EXTENSION_DIRECTORY).split(";");
        String jrePath = allExtensionDirectories[0];
        jrePath = jrePath.substring(0, jrePath.length() - ("/ext").length());
        
        try {
            File jreFolder = new File(jrePath);
            List<File> allFiles = getFiles(jreFolder);
            List<String> classNames = getClassNames(allFiles);
            System.out.println("Number of Classes Found: "+classNames.size());
            initializeClasses(classNames);
            System.out.println("Number of Java.Lang Classes Loaded: "+loadedClasses);
        }
        catch (IOException e) {
            System.out.println("Could not load JAR classes.");
            e.printStackTrace();
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }

    public List<File> getFiles(File folder) {
        List<File> allFiles = new ArrayList<File>();
        for (File file: folder.listFiles()) {
            if (file.getName().endsWith(JAR_EXTENSION)) {
                allFiles.add(file);
            }
        }
        return allFiles;
    }

    public List<String> getClassNames(List<File> allJARFiles) throws IOException{
        List<String> classNames = new ArrayList<String>();
        for (File file: allJARFiles) {
            JarFile jarFile = new JarFile(file);
            Enumeration<JarEntry> entries = jarFile.entries();
            while(entries.hasMoreElements()) {
                JarEntry entry = entries.nextElement();
                if (entry.getName().endsWith(CLASS_EXTENSION)) {
                    int nameLength = entry.getName().length();
                    String name = entry.getName().substring(0, nameLength - CLASS_EXTENSION.length());
                    name = name.replace('/', '.');
                    if (name.startsWith(LANG_LIBRARY)) {
                        classNames.add(name);
                    }
                    
                }
            }
            jarFile.close();
        }
        return classNames;
    }

    public void initializeClasses(List<String> classNames) {
        for(String name: classNames) {
            try {
                Class.forName(name);
                loadedClasses += 1;
            }
            catch (Exception e) {
                System.out.println("Could not find class file.");
                e.printStackTrace();
            }            
            
        }
    }
}