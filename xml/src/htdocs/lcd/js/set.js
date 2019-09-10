
function startTime(){
			var today=new Date();
			var year=today.getFullYear();
			var month=today.getMonth()+1;
			var day=today.getDate();
			var h=today.getHours();
			var m=today.getMinutes();
			var s=today.getSeconds();// 在小于10的数字前加一个‘0’
			m=checkTime(m);
			s=checkTime(s);
			document.getElementById('txt').innerHTML=year+"年"+month+"月"+day+"日 "+h+":"+m+":"+s;
			t=setTimeout(function(){startTime()},500);
		}
function checkTime(i){
    if (i<10){
        i="0" + i;
    }
    return i;
}
        
function cancle_jump()
{
    window.open("index.html","_self");
}
		
function juge_result()
{

	alert("设置完成后,重启系统生效");
    if(theForm.cross_road_name.value == "")
        {
            alert("路口名不能为空");
            return false;
        }
        else if(theForm.device_id.value == "")
        {
            alert("设备ID不能为空");
            return false;
        }
        return true;
}

 function set_info() 
        {
            if (window.XMLHttpRequest)
            {
                xhttp=new XMLHttpRequest();
               
            }
            else
            {
                xhttp=new ActiveXObject("Microsoft.XMLHTTP");
               
            }

            xhttp.open("GET","../../sysconf.xml",false);
            xhttp.send();
            xmlDoc=xhttp.responseXML;
            
                        document .getElementById ("crossname").value=xmlDoc.getElementsByTagName("EquipID")[0].childNodes[0].nodeValue;
						document .getElementById ("deviceid").value=xmlDoc.getElementsByTagName("EquipName")[0].childNodes[0].nodeValue;
                        x=xmlDoc.getElementsByTagName("system-network")[0];
                        document .getElementById ("ip1").value=x.attributes[0].textContent ; 
                        document .getElementById ("mask1").value=x.attributes[1].textContent ; 
                        document .getElementById ("gateway1").value=x.attributes[2].textContent ;  
                        document .getElementById ("ip2").value=x.attributes[0].textContent ;
                        document .getElementById ("mask2").value=x.attributes[1].textContent ;
                        document .getElementById ("gateway2").value=x.attributes[2].textContent ; 
                        
                        document .getElementById ("a3_define").value=xmlDoc.getElementsByTagName("cur_one_des")[0].childNodes[0].nodeValue;
                        document .getElementById ("a2_define").value=xmlDoc.getElementsByTagName("cur_two_des")[0].childNodes[0].nodeValue;
                        document .getElementById ("a1_define").value=xmlDoc.getElementsByTagName("cur_three_des")[0].childNodes[0].nodeValue;
                        document .getElementById ("b3_define").value=xmlDoc.getElementsByTagName("cur_four_des")[0].childNodes[0].nodeValue;
                        document .getElementById ("b2_define").value=xmlDoc.getElementsByTagName("cur_five_des")[0].childNodes[0].nodeValue;
                        document .getElementById ("b1_define").value=xmlDoc.getElementsByTagName("cur_six_des")[0].childNodes[0].nodeValue;
                        document .getElementById ("c3_define").value=xmlDoc.getElementsByTagName("cur_seven_des")[0].childNodes[0].nodeValue;
                        document .getElementById ("c2_define").value=xmlDoc.getElementsByTagName("cur_eight_des")[0].childNodes[0].nodeValue;
                        document .getElementById ("c1_define").value=xmlDoc.getElementsByTagName("cur_nine_des")[0].childNodes[0].nodeValue;
                        
                        
                        x=xmlDoc.getElementsByTagName("cur_one_des")[0] ;  
                        document .getElementById ("a3_warn").value=x.getAttribute("th_hold_h");
                        document .getElementById ("a3_warn_l").value=x.getAttribute("th_hold_l");
                        x=xmlDoc.getElementsByTagName("cur_two_des")[0] ;
                        document .getElementById ("a2_warn").value=x.getAttribute("th_hold_h");
                        document .getElementById ("a2_warn_l").value=x.getAttribute("th_hold_l");
                        x=xmlDoc.getElementsByTagName("cur_three_des")[0] ;
                        document .getElementById ("a1_warn").value=x.getAttribute("th_hold_h");
                        document .getElementById ("a1_warn_l").value=x.getAttribute("th_hold_l");
                        x=xmlDoc.getElementsByTagName("cur_four_des")[0] ;
                        document .getElementById ("b3_warn").value=x.getAttribute("th_hold_h");
                        document .getElementById ("b3_warn_l").value=x.getAttribute("th_hold_l");
                        x=xmlDoc.getElementsByTagName("cur_five_des")[0] ;
                        document .getElementById ("b2_warn").value=x.getAttribute("th_hold_h");
                        document .getElementById ("b2_warn_l").value=x.getAttribute("th_hold_l");
                        x=xmlDoc.getElementsByTagName("cur_six_des")[0] ; 
                        document .getElementById ("b1_warn").value=x.getAttribute("th_hold_h");
                        document .getElementById ("b1_warn_l").value=x.getAttribute("th_hold_l");
                        x=xmlDoc.getElementsByTagName("cur_seven_des")[0] ;
                        document .getElementById ("c3_warn").value=x.getAttribute("th_hold_h");
                        document .getElementById ("c3_warn_l").value=x.getAttribute("th_hold_l");
                        x=xmlDoc.getElementsByTagName("cur_eight_des")[0] ; 
                        document .getElementById ("c2_warn").value=x.getAttribute("th_hold_h");
                        document .getElementById ("c2_warn_l").value=x.getAttribute("th_hold_l");
                        x=xmlDoc.getElementsByTagName("cur_nine_des")[0] ; 
                        document .getElementById ("c1_warn").value=x.getAttribute("th_hold_h");
                        document .getElementById ("c1_warn_l").value=x.getAttribute("th_hold_l"); 
                                    
        }
