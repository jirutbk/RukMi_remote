String MAIN_page = R"=====(<!DOCTYPE html>
<html>
<head><meta charset='utf-8'><meta name='viewport' content='width=device-width, initial-scale=1'>
<link rel='icon' href='data:,'>
<style>
	html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}
	.button { background-color: #4CAF50; border: none; color: white; padding: 10px 20px;
		text-decoration: none; font-size: 23px; margin: 2px; cursor: pointer;}
	.buttonCh {background-color: rgb(248, 199, 36); width:150px;border-radius: 12px;}
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
<h1>RukMi remote V 1.2</h1>
<table align='center'>
<tr>	
	<td colspan=2 width=170><button class='button buttonC buttonRed' onclick="sendData('/cmd?cmd=power')">Power</button></td>
	<td width=50>&nbsp;</td>
	<td colspan=2 width=170><button class='button buttonC' onclick="sendData('/cmd?cmd=source')">เสา/จาน</button></td>
</tr>
<tr>
	<td colspan=5>&nbsp;</td>
</tr>
<tr>
	<td>&nbsp;</td>
	<td align='right'><button class='button buttonR buttonBlue' style='width:60px' onclick="sendData('/cmd?cmd=chInc')">+</button></td>
	<td>&nbsp;</td>
	<td align='left'><button class='button buttonR buttonBlue' style='width:60px' onclick="sendData('/cmd?cmd=soundInc')">+</button></td>
	<td>&nbsp;</td>
</tr>
<tr>
	<td colspan=5>&nbsp;</td>
</tr>
<tr>
	<td>&nbsp;</td>
	<td align='right'><button class='button buttonR buttonBlue' style='width:60px' onclick="sendData('/cmd?cmd=chDec')">-</button></td>
	<td>&nbsp;</td>
	<td align='left'><button class='button buttonR buttonBlue' style='width:60px' onclick="sendData('/cmd?cmd=soundDec')">-</button></td>
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
	<td>&nbsp;</td>
	<td colspan=3><button class='button buttonC buttonGreen' onclick="sendData('/cmd?cmd=mute')">ปิดเสียง</button></td>	
	<td>&nbsp;</td>
</tr>
<tr>
	<td colspan=5 align='left' style='font-size:22px'>ช่องรายการ</td>
</tr>
<tr>
	<td colspan=2><button class='button buttonCh' onclick="sendData('/cmd?cmd=ch&num=33')">3 HD</button></td>
	<td colspan=2><button class='button buttonCh' onclick="sendData('/cmd?cmd=ch&num=35')">7 HD</button></td>
</tr>
<tr>
	<td colspan=2><button class='button buttonCh' onclick="sendData('/cmd?cmd=ch&num=29')">Mono</button></td>
	<td colspan=2><button class='button buttonCh' onclick="sendData('/cmd?cmd=ch&num=23')">Workpoint</button></td>
</tr>
<tr>
	<td colspan=2><button class='button buttonCh' onclick="sendData('/cmd?cmd=ch&num=31')">One</button></td>
	<td colspan=2><button class='button buttonCh' onclick="sendData('/cmd?cmd=ch&num=27')">Ch 8</button></td>
</tr>
<tr>
	<td colspan=2><button class='button buttonCh' onclick="sendData('/cmd?cmd=ch&num=32')">ThaiRath</button></td>
	<td colspan=2><button class='button buttonCh' onclick="sendData('/cmd?cmd=ch&num=222')">TrueFilm</button></td>
</tr>
<tr>
	<td colspan=2><button class='button buttonCh' onclick="sendData('/cmd?cmd=ch&num=118')">XZYT</button></td>
	<td colspan=2><button class='button buttonCh' onclick="sendData('/cmd?cmd=ch&num=46')">Movie Hit</button></td>
</tr>
<tr>
	<td colspan=2><button class='button buttonCh' onclick="sendData('/cmd?cmd=ch&num=246')">Fox Thai</button></td>
	<td colspan=2><button class='button buttonCh' onclick="sendData('/cmd?cmd=ch&num=41')">SPKJump</button></td>
</tr>
<tr>
	<td colspan=2><button class='button buttonCh' onclick="sendData('/cmd?cmd=ch&num=39')">EXPWLD</button></td>
	<td colspan=2><button class='button buttonCh' onclick="sendData('/cmd?cmd=ch&num=1')">5 HD</button></td>
</tr>
</table>
</body>
</html>
)=====";
