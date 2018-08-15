package com.dipendughosh.shownotificationdemo;

import android.annotation.TargetApi;
import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.Intent;
import android.graphics.Color;
import android.os.Build;
import android.support.annotation.RequiresApi;
import android.support.v4.app.NotificationCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {

    public static final String NOTIFICATION_CHANNEL_ID = "4565";
    public static final String NOTIFICATION_CHANNEL_NAME = "My channel";
    private Button button;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        button = (Button) findViewById(R.id.button);
        button.setOnClickListener(new View.OnClickListener() {
            @TargetApi(Build.VERSION_CODES.O)
            @RequiresApi(api = Build.VERSION_CODES.JELLY_BEAN)
            @Override
            public void onClick(View v) {
                Intent intent = new Intent();
                CharSequence channelName = NOTIFICATION_CHANNEL_NAME;
                int importance = NotificationManager.IMPORTANCE_LOW;
                NotificationChannel notificationChannel = new NotificationChannel(NOTIFICATION_CHANNEL_ID, NOTIFICATION_CHANNEL_NAME, importance);
                notificationChannel.enableLights(true);
                notificationChannel.setLightColor(Color.RED);
                notificationChannel.enableVibration(true);
                notificationChannel.setVibrationPattern(new long[]{100, 200, 300, 400, 500, 400, 300, 200, 400});
                PendingIntent pendingIntent = PendingIntent.getActivity(MainActivity.this, 0, intent, 0);
                Notification notification = null;
                if (android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.O) {
                    notification = new Notification.Builder(MainActivity.this, NOTIFICATION_CHANNEL_ID)
                                                .setDefaults(Notification.DEFAULT_ALL)
                                                .setTicker("Ticker Title")
                                                .setVibrate(new long[]{100, 200, 300, 400, 500, 400, 300, 200, 400})
                                                .setSound(null)
                                                .setChannelId(NOTIFICATION_CHANNEL_ID)
                                                .setContentTitle("Content Title")
                                                .setContentText("Content Text")
                                                .setPriority(NotificationCompat.PRIORITY_DEFAULT)
                                                .setSmallIcon(R.drawable.ic_launcher_foreground)
                                                .addAction(R.drawable.ic_launcher_background, "Action 1", pendingIntent)
                                                .addAction(R.drawable.ic_launcher_background, "Action 2", pendingIntent)
                                                .setContentIntent(pendingIntent)
                                                .getNotification();
                }
                notification.flags = Notification.FLAG_AUTO_CANCEL;
                NotificationManager notificationManager = (NotificationManager) getSystemService(NOTIFICATION_SERVICE);
                notificationManager.createNotificationChannel(notificationChannel);
                notificationManager.notify(0,notification);
            }
        });
    }
}
