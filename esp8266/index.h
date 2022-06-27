const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="pt-br">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    
    <script src="http://ajax.googleapis.com/ajax/libs/jquery/1.9.1/jquery.min.js"></script>
    <title>Smart House</title>
    <style>.box {
    position: relative;
    margin: auto;
    display: block;
    margin-top: 8%;
    width: 600px;
    height: 600px;
    background: #bbbbbb;
  }
  
  #circle {
    position: absolute;
    width: 40%;
    height: 40%;
    background: white;
    top: 20%;
    left: 30%;
    margin: 0 auto;
    border-radius: 50%;
  }
  
  #trapezoid {
    position: absolute;
    background: white;
    height: 30%;
    width: 40%;
    left: 30%;
    top: 42%;
    -webkit-clip-path: polygon(0 0, 100% 0, 80% 100%, 20% 100%);
  }
  
  #bottom1 {
    position: absolute;
    height: 5%;
    width: 25%;
    background: grey;
    top: 72%;
    left: 37.5%;
    z-index: 1;
  }
  
  #bottom1:before {
    content: "";
    height: 100%;
    width: 20%;
    background: grey;
    display: block;
    position: absolute;
    border-radius: 50%;
    left: -8%;
  }
  
  #bottom1:after {
    content: "";
    height: 100%;
    width: 20%;
    background: grey;
    display: block;
    position: absolute;
    border-radius: 50%;
    right: -8%;
  }
  
  #bottom2 {
    position: absolute;
    height: 5%;
    width: 22%;
    background: grey;
    top: 78%;
    left: 39%;
  }
  
  #bottom2:before {
    content: "";
    height: 100%;
    width: 20%;
    background: grey;
    display: block;
    position: absolute;
    border-radius: 50%;
    left: -8%;
  }
  
  #bottom2:after {
    content: "";
    height: 100%;
    width: 20%;
    background: grey;
    display: block;
    position: absolute;
    border-radius: 50%;
    right: -8%;
  }
  
  #bottom3 {
    position: absolute;
    height: 5%;
    width: 18%;
    background: grey;
    top: 84%;
    left: 41%;
    z-index: 1;
  }
  
  #bottom3:before {
    content: "";
    height: 100%;
    width: 20%;
    background: grey;
    display: block;
    position: absolute;
    border-radius: 50%;
    left: -8%;
  }
  
  #bottom3:after {
    content: "";
    height: 100%;
    width: 20%;
    background: grey;
    display: block;
    position: absolute;
    border-radius: 50%;
    right: -8%;
  }
  
  #shine {
    width: 20%;
    height: 20%;
    background: white;
    border-radius: 50%;
    top: 20%;
    position: absolute;
    left: 18%;
  }
  
  .halfCircle {
    height: 100px;
    width: 100px;
    border-radius: 0 0 90px 90px;
  }
  
  #halfCircle {
    height: 45px;
    width: 90px;
    border-radius: 0 0 90px 90px;
    background: black;
    margin: 0 auto;
    top: 88%;
    position: relative;
  }
  
  .drop {
    width: 8%;
    height: 8%;
    position: absolute;
    border: 15px solid orange;
  }
  
  #left {
    left: 40%;
    top: 50%;
    border-radius: 50% 50% 0 50%;
  }
  
  #left:after {
    content: "";
    height: 117px;
    width: 60px;
    border: 15px solid orange;
    display: block;
    position: absolute;
    left: 98%;
    top: 123%;
  }
  
  #right {
    right: 39%;
    top: 50%;
    border-radius: 50% 50% 50% 0;
  }
  



  .switch {
    position: relative;
    display: inline-block;
    width: 60px;
    height: 34px;
  }
  
  .switch input { 
    opacity: 0;
    width: 0;
    height: 0;
  }
  
  .slider {
    position: absolute;
    cursor: pointer;
    top: -36px;
    left: 191px;
    right: -337px;
    bottom: 2px;
    background-color: #ccc;
    -webkit-transition: .4s;
    transition: .4s;
  }
  
  .slider:before {
    position: absolute;
    content: "";
    height: 60px;
    width: 59px;
    left: 10px;
    bottom: 4px;
    background-color: white;
    -webkit-transition: .4s;
    transition: .4s;
  }
  
  input:checked + .slider {
    background-color: #00f064;
  }
  
  input:focus + .slider {
    box-shadow: 0 0 1px #00f064;
  }
  
  input:checked + .slider:before {
    -webkit-transform: translateX(26px);
    -ms-transform: translateX(26px);
    transform: translateX(125px);
  }
  
  /* Rounded sliders */
  .slider.round {
    border-radius: 34px;
  }
  
  .slider.round:before {
    border-radius: 50%;
  }

  .container
  {
    justify-content: center;
    display: flex;
    flex-direction: column;
    flex-wrap: wrap;
  }

  .block {
    width: 90px;
    flex: 0 0 50px;
    margin: 5px;
  }
  *, *:before, *:after {
  box-sizing: border-box;
  margin: 0;
  padding: 0;
}
:root {
  /* minFontSize + (maxFontSize - minFontSize) * (100vw - minVWidth)/(maxVWidth - minVWidth) */
  font-size: calc(64px + (80 - 64) * (100vw - 320px)/(960 - 320));
}
body, input {
  font-size: 60px;
  line-height: 1.5;
}
body {
  background: #bbb;
}
input {
  display: block;
  margin-bottom: 1.5em;
}
form.main {
  padding: 1.5em 0 0 0;
  text-align: right;  
}

.content {
  display: flex;
  flex-flow: row wrap;
  align-items: center;
}

.l {
  background-color: rgba(0,0,0,0.7);
  border-radius: 0.75em;
  box-shadow: 0.125em 0.125em 0 0.125em rgba(0,0,0,0.3) inset;
  color: #fdea7b;
  display: inline-flex;
  align-items: center;
  margin: auto;
  padding: 0.15em;
  width: 3em;
  height: 1.5em;
  transition: background-color 0.1s 0.3s ease-out, box-shadow 0.1s 0.3s ease-out;
  -webkit-appearance: none;
  -moz-appearance: none;
  appearance: none;
}
.l:before, .l:after {
  content: "";
  display: block;
}
.l:before {
  background-color: #d7d7d7;
  border-radius: 50%;
  width: 1.2em;
  height: 1.2em;
  transition: background-color 0.1s 0.3s ease-out, transform 0.3s ease-out;
  z-index: 1;
}
.l:after {
  background:
    linear-gradient(transparent 50%, rgba(0,0,0,0.15) 0) 0 50% / 50% 100%,
    repeating-linear-gradient(90deg,#bbb 0,#bbb,#bbb 20%,#999 20%,#999 40%) 0 50% / 50% 100%,
    radial-gradient(circle at 50% 50%,#888 25%, transparent 26%);
  background-repeat: no-repeat;
  border: 0.25em solid transparent;
  border-left: 0.4em solid #d8d8d8;
  border-right: 0 solid transparent;
  transition: border-left-color 0.1s 0.3s ease-out, transform 0.3s ease-out;
  transform: translateX(-22.5%);
  transform-origin: 25% 50%;
  width: 1.2em;
  height: 1em;
}
/* Checked */
.l:checked {
  background-color: rgba(0,0,0,0.45);
  box-shadow: 0.125em 0.125em 0 0.125em rgba(0,0,0,0.1) inset;
}
.l:checked:before {
  background-color: currentColor;
  transform: translateX(125%)
}
.l:checked:after {
  border-left-color: currentColor;
  transform: translateX(-2.5%) rotateY(180deg);
}
/* Other States */
.l:focus {
  /* Usually an anti-A11Y practice but set to remove an annoyance just for this demo */
  outline: 0;
}</style>
</head>

<body>
  
    <div class="container">
        <div  class ="block" style="display:table; align-items:center;">
            <div class='box' id='box1' style="cursor: pointer;display: inline-block"  name="checkyel">
                <div id='circle'>
                <div id='shine'></div>
                </div>
                <div id='trapezoid'></div>
                <div id='bottom1'></div>
                <div id='bottom2'></div>
                <div id='bottom3'></div>
            
                <div id='halfCircle'></div>
            
                <div class='drop' id='left'></div>
                <div class='drop' id='right'></div>
            
                <div id='wire'></div>
            
            </div>
    
            
            <div style="cursor: pointer;display: inline-block; position:absolute;top:365px" >
                <h4>Turn On/Off Led</h4>
                    <label class="switch" style="left:-80px">
                        <input type="checkbox" id="ctrl_button">
                        <span class="slider round"></span>
                    </label>
            </div>
    
            
        </div>
   
        <div  class ="block" style="display:table; align-items:center; padding-left:170px;">
            <div class='box2' id='box2' style="cursor: pointer;display: inline-block"  name="checkgate">
                <img id ="img_gate" src="https://res.cloudinary.com/sacchidananad-utech/image/upload/v1656066496/samples/Dat/close_tjabyf.png" style="width:300px;">
            
            </div>
    
            
            <div style="cursor: pointer;display: inline-block; position: absolute; padding-left:100px" >
                <h4>Open / Close Gateway</h4>
                    <label class="switch" style="left:-37px">
                        <input type="checkbox" id="ctrl_button2">
                        <span class="slider round"></span>
                    </label>
            </div>
    
            
        </div>
    
    </div>

    <script>
        status_led1 = false
        status_gate = false;
        function turnLedOn(id){
            circle = '#' + id + ' #circle'
            trapezoid = '#' + id + ' #trapezoid'
            if (!status_led1)
            {
                $(circle).css('background-color','green');
                $(trapezoid).css('background-color', 'green');
                status_led1 = true;
                var xhr = new XMLHttpRequest();
                xhr.open("GET", "/Led?output=on", true);
                xhr.send();
            }
            else
            {
                $(circle).css('background-color','white');
                $(trapezoid).css('background-color', 'white');
                status_led1 = false;
                var xhr = new XMLHttpRequest();
                xhr.open("GET", "/Led?output=off", true);
                xhr.send();
            }
        }
        ///
         
   setInterval(function () {
     var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
          if(xhttp.responseText == "o")
          {
             status_gate = true;
             img_gate.src = "https://res.cloudinary.com/sacchidananad-utech/image/upload/v1656066496/samples/Dat/open_nwzwln.png";
             $('input[id="ctrl_button2"]').prop("checked", true);
             console.log('o send');
             
          }
          if(xhttp.responseText == "c")
          {
             status_gate = false;
             img_gate.src = "https://res.cloudinary.com/sacchidananad-utech/image/upload/v1656066496/samples/Dat/close_tjabyf.png";
             $('#ctrl_button2').removeAttr("checked");
             console.log('c send');
          }
        }
      };
      xhttp.open("GET", "/status_gate", true);
      xhttp.send();
    }, 500);

         
        function manageGate(img_gate)
        {
            if (status_gate == false)
            {
                img_gate.src = "https://res.cloudinary.com/sacchidananad-utech/image/upload/v1656066496/samples/Dat/open_nwzwln.png";
                status_gate = true;
                
                var xhr = new XMLHttpRequest();
                xhr.open("GET", "/Gate?output=open", true);
                xhr.send();
                
            }
            else{
                img_gate.src = "https://res.cloudinary.com/sacchidananad-utech/image/upload/v1656066496/samples/Dat/close_tjabyf.png";
                status_gate = false;
                var xhr = new XMLHttpRequest();
                xhr.open("GET", "/Gate?output=close", true);
                xhr.send();
            }
        }
        
        let ctrl_button = document.querySelector('#ctrl_button');
        let ctrl_button2 = document.querySelector('#ctrl_button2');
        ctrl_button.onclick = handleClick("ctrl_button")
        ctrl_button2.onclick = handleClick("ctrl_button2")

        function handleClick(id) {
            return () => {
                if (id == 'ctrl_button')
                {
                    turnLedOn('box1')
                }
                if (id == 'ctrl_button2')
                {
                    var img_gate = document.getElementById("img_gate");
                    manageGate(img_gate)
                }
            }
        }

    </script>
</body>

</html>

)=====";
