package com.dipendughosh.notificationdemo;

import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.os.Build;
import android.support.v4.app.NotificationCompat;
import android.support.v4.app.NotificationManagerCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.RemoteViews;

public class ExpandableNotificationActivity extends AppCompatActivity {

    public static final String CHANNEL_ID = "personal_notification";
    public static final int NOTIFICATION_ID = 001;
    public static final String TXT_REPLY = "text reply";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_expandable_notification);
    }

    public void displayNotification(View view) {
        createNotificationChannel();
        RemoteViews normal_layout = new RemoteViews(getPackageName(), R.layout.custome_layout);
        RemoteViews expanded_layout = new RemoteViews(getPackageName(), R.layout.custome_expanded_layout);


        NotificationCompat.Builder builder = new NotificationCompat.Builder(this, CHANNEL_ID);
        builder.setSmallIcon(R.drawable.ic_sms_notification);
        //builder.setContentTitle("Simple Notification");
        //builder.setContentText("This is my first notification");
        builder.setPriority(NotificationCompat.PRIORITY_DEFAULT);

        builder.setStyle(new NotificationCompat.DecoratedCustomViewStyle());
        builder.setCustomContentView(normal_layout);
        builder.setCustomBigContentView(expanded_layout);
        /*Bitmap bitmap = BitmapFactory.decodeResource(getResources(), R.drawable.ic_menu_achievement);
        builder.setLargeIcon(bitmap);
        builder.setStyle(new NotificationCompat.BigPictureStyle().bigPicture(bitmap).bigLargeIcon(null));*/

        //builder.setStyle(new NotificationCompat.BigTextStyle().bigText(getString(R.string.notification_text)));


        NotificationManagerCompat notificationManagerCompat = NotificationManagerCompat.from(this);
        notificationManagerCompat.notify(NOTIFICATION_ID,builder.build());


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
