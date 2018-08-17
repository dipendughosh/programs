package com.dipendughosh.sqllitedetaileddemo;


import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;


/**
 * A simple {@link Fragment} subclass.
 */
public class DeleteContactFragment extends Fragment {

    private EditText Delete_Id;
    private Button bnDelete;

    public DeleteContactFragment() {
        // Required empty public constructor
    }


    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_delete_contact, container, false);
        bnDelete =view.findViewById(R.id.bn_delete);
        Delete_Id = view.findViewById(R.id.txt_delete_contact_id);
        bnDelete.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int id = Integer.parseInt(Delete_Id.getText().toString());

                ContactDbHelper contactDbHelper = new ContactDbHelper(getActivity());
                SQLiteDatabase database = contactDbHelper.getWritableDatabase();
                contactDbHelper.deleteContact(id, database);
                contactDbHelper.close();
                Delete_Id.setText("");
                Toast.makeText(getActivity(), "Contact Deleted☻ Successfully...", Toast.LENGTH_SHORT).show();
            }
        });
        // Inflate the layout for this fragment
        return view;
    }

}
