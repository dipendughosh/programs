package com.dipendughosh.notificationdemo;

import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.Intent;
import android.os.Build;
import android.support.v4.app.NotificationCompat;
import android.support.v4.app.NotificationManagerCompat;
import android.support.v4.app.RemoteInput;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

public class ProgressBarActivity extends AppCompatActivity {

    public static final String CHANNEL_ID = "personal_notification";
    public static final int NOTIFICATION_ID = 001;
    public static final String TXT_REPLY = "text reply";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_progress_bar);
    }

    public void displayNotification(View view) {
        createNotificationChannel();

        final NotificationCompat.Builder builder = new NotificationCompat.Builder(this, CHANNEL_ID);
        builder.setSmallIcon(R.drawable.ic_download);
        builder.setContentTitle("Image Download");
        builder.setContentText("Download in progress");
        builder.setPriority(NotificationCompat.PRIORITY_DEFAULT);
        final NotificationManagerCompat notificationManagerCompat = NotificationManagerCompat.from(this);
        final int max_progress = 100;
        int current_progress = 0;
        //determinate false
        //builder.setProgress(max_progress, current_progress, false);
        //indeterminate true
        builder.setProgress(0, 0, true);
        notificationManagerCompat.notify(NOTIFICATION_ID,builder.build());

        Thread thread = new Thread() {
            @Override
            public void run() {
                int count = 0;
                try {
                    while (count <= 100) {
                        count = count + 10;
                        sleep(1000);
                        //builder.setProgress(max_progress, count, false);
                        //notificationManagerCompat.notify(NOTIFICATION_ID,builder.build());
                    }
                    builder.setContentText("Download Complete");
                    builder.setProgress(0,0,false);
                    notificationManagerCompat.notify(NOTIFICATION_ID,builder.build());
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        };

        thread.start();
    }

    private  void createNotificationChannel() {
        if(Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            CharSequence name = "Personal Notification";
            String description = "Include all the personal notification";
            int importance = NotificationManagerCompat.IMPORTANCE_DEFAULT;

            NotificationChannel notificationChannel = new NotificationChannel(CHANNEL_ID, name, importance);
            notificationChannel.setDescription(description);

            NotificationManager notificationManager = (NotificationManager) getSystemService((NOTIFICATION_SERVICE));
            notificationManager .createNotificationChannel(notificationChannel);
        }
    }
}
