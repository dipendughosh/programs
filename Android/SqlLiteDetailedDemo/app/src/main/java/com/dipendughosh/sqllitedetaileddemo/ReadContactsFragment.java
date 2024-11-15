package com.dipendughosh.sqllitedetaileddemo;

import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;


public class ReadContactsFragment extends Fragment {

    private TextView Txt_Display;

    public ReadContactsFragment() {
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_read_contacts, container, false);
        Txt_Display = view.findViewById(R.id.txt_display);
        readContacts();
        // Inflate the layout for this fragment
        return view;
    }

    private void readContacts() {

        ContactDbHelper contactDbHelper = new ContactDbHelper(getActivity());
        SQLiteDatabase database = contactDbHelper.getReadableDatabase();

        Cursor cursor = contactDbHelper.readContacts(database);
        String info = "";

        while (cursor.moveToNext()) {

            String id = Integer.toString(cursor.getInt(cursor.getColumnIndex(ContactContract.ContactEntry.CONTACT_ID)));
            String name = cursor.getString(cursor.getColumnIndex(ContactContract.ContactEntry.NAME));
            String email = cursor.getString(cursor.getColumnIndex(ContactContract.ContactEntry.EMAIL));

            info = info+"\n\nId : " + id + "\nName : " + name + "\nEmail : " + email;
        }

        Txt_Display.setText(info);
        contactDbHelper.close();
    }
}
