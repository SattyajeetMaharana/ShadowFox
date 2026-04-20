import java.applet.Applet;
import java.awt.Graphics;

/* 
<applet code="First.class" width="150" height="150">
</applet>
*/
public class First extends Applet{
    public void paint(Graphics g) {
        g.drawString("Welcome", 150, 150);
    }
}
