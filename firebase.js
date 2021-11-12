var firebaseConfig = {
    apiKey: "AIzaSyA-uHwYxs-xUCHYL1sNjPFfy8oBiWJyVdE",
    authDomain: "light-web.firebaseapp.com",
    databaseURL: "https://light-web-default-rtdb.firebaseio.com",
    projectId: "light-web",
    storageBucket: "light-web.appspot.com",
    messagingSenderId: "980096008717",
    appId: "1:980096008717:web:e460c8b82f3ec0fececb44",
    measurementId: "G-W84S124FCK"
};
firebase.initializeApp(firebaseConfig);
var database = firebase.database();

function myFunction() {
    var checkBox1 = document.getElementById("LED1");
    if (checkBox1.checked == true) {
        console.log("ON")
        database.ref('LED1').set(1);
    } else {
        console.log("OFF")
        database.ref('LED1').set(0);
    }
    var checkBox2 = document.getElementById("LED2");
    if (checkBox2.checked == true) {
        console.log("ON")
        database.ref('LED2').set(1);
    } else {
        console.log("OFF")
        database.ref('LED2').set(0);
    }
}