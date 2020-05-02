const char FULL_page[] PROGMEM = R"=====(<!DOCTYPE html>
<html>
<head><meta charset='utf-8'><meta name='viewport' content='width=device-width, initial-scale=1'>
<link rel='icon' href='data:,'>
<style>
	html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}
	.button { background-color: #4CAF50; border: none; color: white; padding: 10px 20px;
		text-decoration: none; font-size: 20px; margin: 2px; cursor: pointer;}
	.buttonCh {background-color: rgb(248, 199, 36); width:150px;border-radius: 12px;}
	.buttonNum {background-color: rgb(10, 95, 253); width:50px;border-radius: 35px;}
	.buttonR{border-radius: 12px;}
	.buttonC{border-radius: 50px;}
	.buttonBlue {background-color: #008CBA;}
	.buttonRed {background-color: #f44336;}
	.buttonGreen {background-color: #4CAF50;}	
</style>
<script>
function sendData(getUrl) {
  var xhttp = new XMLHttpRequest();
  xhttp.open("GET", getUrl, true);
  xhttp.send();
}
</script>
</head>
<body>
<h1>RukMi remote V 1.0</h1>
<table align='center'>
<tr>	
	<td colspan=2 width=170><button class='button buttonC buttonRed' onclick="sendData('/power')">Power</button></td>
	<td width=50>&nbsp;</td>
	<td colspan=2 width=170><button class='button buttonC' onclick="sendData('/source')">SAT/T2</button></td>
</tr>
<tr>
	<td colspan=5>&nbsp;</td>
</tr>
<tr>
	<td>&nbsp;</td>
	<td align='right'><button class='button buttonR buttonBlue' style='width:60px' onclick="sendData('/ch/inc')">+</button></td>
	<td>&nbsp;</td>
	<td align='left'><button class='button buttonR buttonBlue' style='width:60px' onclick="sendData('/sound/inc')">+</button></td>
	<td>&nbsp;</td>
</tr>
<tr>
	<td colspan=5>&nbsp;</td>
</tr>
<tr>
	<td>&nbsp;</td>
	<td align='right'><button class='button buttonR buttonBlue' style='width:60px' onclick="sendData('/ch/dec')">-</button></td>
	<td>&nbsp;</td>
	<td align='left'><button class='button buttonR buttonBlue' style='width:60px' onclick="sendData('/sound/dec')">-</button></td>
	<td>&nbsp;</td>
</tr>
<tr>
	<td>&nbsp;</td>
	<td align='right' style='font-size:20px'>ช่อง&nbsp;&nbsp;&nbsp</td>
	<td>&nbsp;</td>
	<td align='left' style='font-size:20px'>&nbsp;&nbsp;เสียง</td>
	<td>&nbsp;</td>
</tr>
<tr>
	<td colspan=5>&nbsp;</td>
</tr>
<tr>
	<td colspan=5><button class='button buttonC buttonGreen' onclick="sendData('/info')">INFO</button>&nbsp;&nbsp;&nbsp;&nbsp;
	<button class='button buttonC buttonGreen' onclick="sendData('/mute')">MUTE</button>&nbsp;&nbsp;&nbsp;&nbsp;	
	<button class='button buttonC buttonGreen' onclick="sendData('/exit')">EXIT</button></td>
</tr>
<tr>
	<td colspan=5>&nbsp;</td>
</tr>
<tr>
	<td colspan=5>
		<button class='button buttonNum' onclick="sendData('/ch/1')">1</button>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
		<button class='button buttonNum' onclick="sendData('/ch/2')">2</button>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
		<button class='button buttonNum' onclick="sendData('/ch/3')">3</button>
	</td>	
</tr>
<tr><td colspan=5>&nbsp;</td></tr>
<tr>
	<td colspan=5>
		<button class='button buttonNum' onclick="sendData('/ch/4')">4</button>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
		<button class='button buttonNum' onclick="sendData('/ch/5')">5</button>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
		<button class='button buttonNum' onclick="sendData('/ch/6')">6</button>
	</td>	
</tr>
<tr><td colspan=5>&nbsp;</td></tr>
<tr>
	<td colspan=5>
		<button class='button buttonNum' onclick="sendData('/ch/7')">7</button>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
		<button class='button buttonNum' onclick="sendData('/ch/8')">8</button>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
		<button class='button buttonNum' onclick="sendData('/ch/9')">9</button>
	</td>	
</tr>
<tr><td colspan=5>&nbsp;</td></tr>
<tr>
	<td colspan=5>
		<button class='button buttonNum' onclick="sendData('/ch/0')">0</button>
	</td>	
</tr>
</table>
</body>
</html>
)=====";
