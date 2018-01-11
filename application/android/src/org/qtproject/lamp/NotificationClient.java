
package org.qtproject.example.notification;

import android.app.Notification;
import android.app.NotificationManager;
import android.content.Context;
import android.os.Vibrator;
import android.util.Log;

public class NotificationClient extends org.qtproject.qt5.android.bindings.QtActivity
{
    private static NotificationManager m_notificationManager;
    private static Notification.Builder m_builder;
    private static NotificationClient m_instance;

    public NotificationClient()
    {
        m_instance = this;
    }

    public static int notify(String s)
    {
        Log.d("abc","abc");
        if (m_notificationManager == null) {
            m_notificationManager = (NotificationManager)m_instance.getSystemService(Context.NOTIFICATION_SERVICE);
            m_builder = new Notification.Builder(m_instance);
            m_builder.setContentTitle("A message from Qt!");
        }

        m_builder.setContentText(s);
        m_notificationManager.notify(1, m_builder.build());
        Vibrator v = (Vibrator) m_instance.getSystemService(Context.VIBRATOR_SERVICE);
         // Vibrate for 500 milliseconds
         v.vibrate(2000);
         return 10;
    }

    public static int return3(String s)
    {
        Vibrator v = (Vibrator) m_instance.getSystemService(Context.VIBRATOR_SERVICE);
         // Vibrate for 500 milliseconds
         v.vibrate(2000);
        return 3;
    }

}
