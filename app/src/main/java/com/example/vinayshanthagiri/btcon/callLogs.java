package com.example.vinayshanthagiri.btcon;

import android.database.Cursor;
import android.provider.CallLog;
import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import java.util.Date;

import static android.provider.CallLog.*;


public class callLogs extends ActionBarActivity {

    TextView textView = null;
    EditText numberIn;
    Button changeNum;
    String numberInput = "12345";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_call_logs);
        textView = (TextView) findViewById(R.id.calllog_txt);
        //numberIn = (EditText)findViewById(R.id.number);
        changeNum = (Button) findViewById(R.id.changeNmBt);

        changeNum.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {

                //numberInput= String.valueOf(numberIn.getText().toString());
                getCallDetails();
            }
        });

        getCallDetails();
    }

    private int getCallDetails() {
        StringBuffer sb = new StringBuffer();
        String strOrder = Calls.DATE + " DESC";
        int callCount=0;
        int callCountTotal=0;
  /* Query the CallLog Content Provider */
        Cursor managedCursor = getContentResolver().query(Calls.CONTENT_URI, null,
                null, null, strOrder);
        int number = managedCursor.getColumnIndex(Calls.NUMBER);
        int type = managedCursor.getColumnIndex(Calls.TYPE);
        int date = managedCursor.getColumnIndex(Calls.DATE);
        int duration = managedCursor.getColumnIndex(Calls.DURATION);




        sb.append("Call Log :");
        while (managedCursor.moveToNext()) {

            if(managedCursor.getString(number).contains(numberInput)) {
                callCount=callCount+1;



            String phNum = managedCursor.getString(number);
            String callTypeCode = managedCursor.getString(type);
            String strcallDate = managedCursor.getString(date);
            Date callDate = new Date(Long.valueOf(strcallDate));
            String callDuration = managedCursor.getString(duration);
            String callType = null;
            int callcode = Integer.parseInt(callTypeCode);


            switch (callcode) {
                case Calls.OUTGOING_TYPE:
                    callType = "Outgoing";
                    break;
                case Calls.INCOMING_TYPE:
                    callType = "Incoming";
                    break;
                case Calls.MISSED_TYPE:
                    callType = "Missed";
                    break;
            }

            sb.append("\nPhone Number:--- " + phNum + " \nCall Type:--- "
                    + callType + " \nCall Date:--- " + callDate
                    + " \nCall duration in sec :--- " + callDuration);
            sb.append("\n----------------------------------"+callCount);

            }
            callCountTotal=callCount;
        }
        managedCursor.close();
        textView.setText("Call count"+"="+callCountTotal+"\n"+"Details"+sb);
        return callCountTotal;
    }


    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_call_logs, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }
}
