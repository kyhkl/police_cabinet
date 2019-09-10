
// 666 keyboard function
var cars=new Array(),i=0;
var cmp_str="102-102-102"//计算键盘6 
var cmp_str1="54-54-54"//多功能键盘6    
function showKeyCode(event)
    {
        cars[i++]= event.keyCode;
        var str = cars.join('-');//转化为字符串
        if((str == cmp_str)||(str == cmp_str1))//比较
        {
             window.open("../../set.html","_self");
             i=0;
             cars[0]=0;
             cars[1]=0;
             cars[2]=0;
        } 
        if(i>=3)//这里不对数组清零无论在任何时候输入666都可以响应
        i=0;
    } 
    
// time update
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

        
function loadXMLDoc()
        {
            var xmlhttp;
            
            if (window.XMLHttpRequest)
            {
                // IE7+, Firefox, Chrome, Opera, Safari 浏览器执行代码
                xmlhttp=new XMLHttpRequest();
            }
            else
            {
                // IE6, IE5 浏览器执行代码 
                xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
            }
            xmlhttp.onreadystatechange=function()
            {
                if (xmlhttp.readyState==4 && xmlhttp.status==200)
                {
                        var obj= JSON.parse(xmlhttp.responseText);
                       
                              power_info_refresh(obj);//更新数据	   

                }
            }
         
            xmlhttp.open("GET","../../json.txt",true);
            xmlhttp.send();
        }
    
        function doUpdate()   
        {   
                
                loadXMLDoc();
                window.setTimeout("doUpdate()", 1000);//每三秒刷新一次数据
  
        }  
/************************************************echarts***************************************************************************/
// 基于准备好的dom，初始化echarts实例
    var option_a = {
        textStyle:{
                color:'#33CC00',
                fontstyle:'仿宋'	
            },
            grid: {
                left: 30,   //距离左边的距离
                right: 80, //距离右边的距离
                bottom: 20,//距离下边的距离
                top: 10//距离上边的距离
                },
        xAxis: {
             name:'单位(mA)'
        },
        yAxis: {data: ["A1","A2","A3",]},
        series: [{
            id:'bar',
            name: '',
            type: 'bar',
             label: {
                        normal: {
                            position: 'right',
                             formatter:function(params){
                                 
                                 return params.data+'mA';
                                 },
                            show: true,
                            color:'#33CC00',
                            fontSize:'13',
                            },	
                },
                barWidth: '55%',
                 itemStyle:{
                    normal:{
                        color:new echarts.graphic.LinearGradient(1, 0, 0, 0, [{
                            offset: 0,
                            color: '#00b0ff'
                        }, {
                            offset: 0.8,
                            color: '#7052f4'
                        }], false),
                         barBorderRadius: 10,
                    }
                },
            data: [0,0,0],
            }],
        };

        var option_b = {
            textStyle:{
                    color:'#CC3300',
                    fontstyle:'仿宋'	
                },
                grid: {
                left: 30,   //距离左边的距离
                right: 80, //距离右边的距离
                bottom: 20,//距离下边的距离
                top: 10//距离上边的距离
                },
            xAxis: {
                 name:'单位(mA)'
            },
            yAxis: {data: ["B1","B2","B3",]},
            series: [{
                id:'bar',
                name: '',
                type: 'bar',
                 label: {
                            normal: {
                                position: 'right',
                                 formatter:function(params){
                                     
                                     return params.data+'mA';
                                     },
                                show: true,
                                color:'#CC3300',
                                fontSize:'13',
                                },	
                    },
                    barWidth: '55%',
                     itemStyle:{
                        normal:{
                            color:new echarts.graphic.LinearGradient(1, 0, 0, 0, [{
                                offset: 0,
                                color: '#00b0ff'
                            }, {
                                offset: 0.8,
                                color: '#7052f4'
                            }], false),
                             barBorderRadius: 10,
                        }
                    },
                data: [0,0,0],
            }],
        };
   
        var option_c = {
            textStyle:{
                    color:'#FFCC00',
                    fontstyle:'仿宋'	
                },
            grid: {
                left: 30,   //距离左边的距离
                right: 80, //距离右边的距离
                bottom: 20,//距离下边的距离
                top: 10//距离上边的距离
                },
            xAxis: {
                 name:'单位(mA)'
            },
            yAxis: {data: ["C1","C2","C3",]},
            series: [{
                id:'bar',
                name: '',
                type: 'bar',
                 label: {
                            normal: {
                                position: 'right',
                                 formatter:function(params){
                                     
                                     return params.data+'mA';
                                     },
                                show: true,
                                color:'#FFCC00',
                                fontSize:'13',
                                },	
                    },
                    barWidth: '55%',
                     itemStyle:{
                        normal:{
                            color:new echarts.graphic.LinearGradient(1, 0, 0, 0, [{
                                offset: 0,
                                color: '#00b0ff'
                            }, {
                                offset: 0.8,
                                color: '#7052f4'
                            }], false),
                             barBorderRadius: 10,
                        }
                    },
                data: [0,0,0],
            }],
        };          
        var myChart_a;
        var myChart_b;
        var myChart_c;
/************************************************charts_a()***************************************************************************/
         function charts_a()
                  {  
                    // 基于准备好的dom，初始化echarts实例
                    myChart_a = echarts.init(document.getElementById('Phase_A'));
                    myChart_a.setOption(option_a);	
                }                              
/************************************************charts_c()***************************************************************************/
         function charts_b()
                  {  
                    // 基于准备好的dom，初始化echarts实例
                    myChart_b = echarts.init(document.getElementById('Phase_B'));
                    myChart_b.setOption(option_b);	
                }                            
                                       
/************************************************charts_c()***************************************************************************/
         function charts_c()
                  {  
                    // 基于准备好的dom，初始化echarts实例
                    myChart_c = echarts.init(document.getElementById('Phase_C'));
                    myChart_c.setOption(option_c);	
                }
                
            //------------------------------------ prase define
     var warn = new Array();
     var warn_l = new Array();
    function prase_define() 
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
          document .getElementById ("A3").value=xmlDoc.getElementsByTagName("cur_one_des")[0].childNodes[0].nodeValue; 
          document .getElementById ("A2").value=xmlDoc.getElementsByTagName("cur_two_des")[0].childNodes[0].nodeValue;
          document .getElementById ("A1").value=xmlDoc.getElementsByTagName("cur_three_des")[0].childNodes[0].nodeValue; 
          document .getElementById ("B3").value=xmlDoc.getElementsByTagName("cur_four_des")[0].childNodes[0].nodeValue; 
          document .getElementById ("B2").value=xmlDoc.getElementsByTagName("cur_five_des")[0].childNodes[0].nodeValue; 
          document .getElementById ("B1").value=xmlDoc.getElementsByTagName("cur_six_des")[0].childNodes[0].nodeValue; 
          document .getElementById ("C3").value=xmlDoc.getElementsByTagName("cur_seven_des")[0].childNodes[0].nodeValue; 
          document .getElementById ("C2").value=xmlDoc.getElementsByTagName("cur_eight_des")[0].childNodes[0].nodeValue;
          document .getElementById ("C1").value=xmlDoc.getElementsByTagName("cur_nine_des")[0].childNodes[0].nodeValue;
     
          document .getElementById ("equipment").rows[0].cells[1].innerHTML=xmlDoc.getElementsByTagName("EquipName")[0].childNodes[0].textContent;
          document .getElementById ("equipment").rows[0].cells[3].innerHTML=xmlDoc.getElementsByTagName("EquipID")[0].childNodes[0].textContent;
          
          x=xmlDoc.getElementsByTagName("cur_one_des")[0] ; 
          warn[0]= x.getAttribute("th_hold_h");
          warn_l[0]= x.getAttribute("th_hold_l");
          x=xmlDoc.getElementsByTagName("cur_two_des")[0] ;
          warn[1]= x.getAttribute("th_hold_h");
          warn_l[1]= x.getAttribute("th_hold_l");
          x=xmlDoc.getElementsByTagName("cur_three_des")[0] ;
          warn[2]= x.getAttribute("th_hold_h");
          warn_l[2]= x.getAttribute("th_hold_l");
          x=xmlDoc.getElementsByTagName("cur_four_des")[0] ;
          warn[3]= x.getAttribute("th_hold_h");
          warn_l[3]= x.getAttribute("th_hold_l");
          x=xmlDoc.getElementsByTagName("cur_five_des")[0] ;
          warn[4]= x.getAttribute("th_hold_h");
          warn_l[4]= x.getAttribute("th_hold_l");
          x=xmlDoc.getElementsByTagName("cur_six_des")[0] ;
          warn[5]= x.getAttribute("th_hold_h");
          warn_l[5]= x.getAttribute("th_hold_l");
          x=xmlDoc.getElementsByTagName("cur_seven_des")[0] ;
          warn[6]= x.getAttribute("th_hold_h");
          warn_l[6]= x.getAttribute("th_hold_l");
          x=xmlDoc.getElementsByTagName("cur_eight_des")[0] ;
          warn[7]= x.getAttribute("th_hold_h");
          warn_l[7]= x.getAttribute("th_hold_l");
          x=xmlDoc.getElementsByTagName("cur_nine_des")[0] ;
          warn[8]= x.getAttribute("th_hold_h");
          warn_l[8]= x.getAttribute("th_hold_l");
         
        }
//------------------------------------------reflash data info
   
var warn=new Array();
var warn_l=new Array();		
function power_info_refresh(obj)
{
    var i=0;
        
        x=document.getElementById("PhaseA");					
        x.rows[0].cells[2].innerHTML =obj.MZR.DATA.msg_info.current[3]+obj.MZR.DATA.msg_info.current[4]+obj.MZR.DATA.msg_info.current[5]+'mA';
        
        x=document.getElementById("PhaseB");						
        x.rows[0].cells[2].innerHTML =obj.MZR.DATA.msg_info.current[6]+obj.MZR.DATA.msg_info.current[7]+obj.MZR.DATA.msg_info.current[8]+'mA';
        
        x=document.getElementById("PhaseC");						
        x.rows[0].cells[2].innerHTML =obj.MZR.DATA.msg_info.current[9]+obj.MZR.DATA.msg_info.current[10]+obj.MZR.DATA.msg_info.current[11]+'mA';
        
        x=document.getElementById("Hz");
        x.value=parseInt(obj.ELE_EM.DATA.data[17]*0.01);
        x=document.getElementById("Ua");
        x.value=parseInt(obj.ELE_EM.DATA.data[3]*0.1);
        x=document.getElementById("Ub");
        x.value=parseInt(obj.ELE_EM.DATA.data[4]*0.1);
        x=document.getElementById("Uc");
        x.value=parseInt(obj.ELE_EM.DATA.data[5]*0.1);
        x=document.getElementById("Ia");
        x.value=obj.ELE_EM.DATA.data[6];
        x=document.getElementById("Ib");
        x.value=obj.ELE_EM.DATA.data[7];
        x=document.getElementById("Ic");
        x.value=obj.ELE_EM.DATA.data[8];
        x=document.getElementById("UT_P");
        x.value=parseInt(obj.ELE_EM.DATA.data[9]*0.1);
        x=document.getElementById("Ua_P");
        x.value=parseInt(obj.ELE_EM.DATA.data[10]*0.1);
        x=document.getElementById("Ub_P");
        x.value=parseInt(obj.ELE_EM.DATA.data[11]*0.1);
        x=document.getElementById("Uc_P");
        x.value=parseInt(obj.ELE_EM.DATA.data[12]*0.1);
        x=document.getElementById("UT_PV");
        x.value=parseInt(obj.ELE_EM.DATA.data[13]*0.1);
        x=document.getElementById("Ua_PV");
        x.value=parseInt(obj.ELE_EM.DATA.data[14]*0.1);
        x=document.getElementById("Ub_PV");
        x.value=parseInt(obj.ELE_EM.DATA.data[15]*0.1);
        x=document.getElementById("Uc_PV");
        x.value=parseInt(obj.ELE_EM.DATA.data[16]*0.1);
        
    for(i=0;i<3;i++)
    {	
      option_a.series[0].data[i]=obj.MZR.DATA.msg_info.current[i+3];
      option_b.series[0].data[i]=obj.MZR.DATA.msg_info.current[i+6];
      option_c.series[0].data[i]=obj.MZR.DATA.msg_info.current[i+9];				  
    }
    // 使用刚指定的配置项和数据显示图表。
    myChart_a.setOption(option_a);
    myChart_b.setOption(option_b);
    myChart_c.setOption(option_c);	
     if (window.XMLHttpRequest)
            {
                xhttp=new XMLHttpRequest();
            }
            else
            {
                xhttp=new ActiveXObject("Microsoft.XMLHTTP");
            }
            xhttp.open("GET","../../log.txt",false);
            xhttp.send();
            var s = xhttp.responseText;
            
            var n = s.lastIndexOf("\n"); 
            var tmp_n;
            var i = 100;
            while(i--)
            {
                if(n == -1)
                    break;
                tmp_n = n;
                n = s.lastIndexOf("\n",n-1);   
            }
            var s1=  s.slice(tmp_n+1,s.length - 1);
            
            x= document.getElementById ("log_txt");
            if(s1 != null)
            x.value=s1;   

    if(option_a.series[0].data[2] >= warn[0])
    {
            document.getElementById('w1').setAttribute('fill','red');
    }
    else if(option_a.series[0].data[2] <= warn_l[0])
            document.getElementById('w1').setAttribute('fill','red');
    else
            document.getElementById('w1').setAttribute('fill','green');  
                 
    if(option_a.series[0].data[1] >= warn[1])
            document.getElementById('w2').setAttribute('fill','red');
    else if(option_a.series[0].data[1] <= warn_l[1])
            document.getElementById('w2').setAttribute('fill','red');
    else
            document.getElementById('w2').setAttribute('fill','green');
            
    if(option_a.series[0].data[0] >= warn[2])
            document.getElementById('w3').setAttribute('fill','red');
    else if(option_a.series[0].data[0] <= warn_l[2])
            document.getElementById('w3').setAttribute('fill','red');
    else
            document.getElementById('w3').setAttribute('fill','green');
            
    if(option_b.series[0].data[2] >= warn[3])
            document.getElementById('w4').setAttribute('fill','red');
    else if(option_b.series[0].data[2] <= warn_l[3])
            document.getElementById('w4').setAttribute('fill','red');
    else
            document.getElementById('w4').setAttribute('fill','green');
            
    if(option_b.series[0].data[1] >= warn[4])
            document.getElementById('w5').setAttribute('fill','red');
    else if(option_b.series[0].data[1] <= warn_l[4])
            document.getElementById('w5').setAttribute('fill','red');
    else
            document.getElementById('w5').setAttribute('fill','green');
            
    if(option_b.series[0].data[0] >= warn[5])
            document.getElementById('w6').setAttribute('fill','red');
    else if(option_b.series[0].data[0] <= warn_l[5])
            document.getElementById('w6').setAttribute('fill','red');
    else
            document.getElementById('w6').setAttribute('fill','green');
            
    if(option_c.series[0].data[2] >= warn[6])
            document.getElementById('w7').setAttribute('fill','red');
    else if(option_c.series[0].data[2] <= warn_l[6])
            document.getElementById('w7').setAttribute('fill','red');
    else
            document.getElementById('w7').setAttribute('fill','green');
            
    if(option_c.series[0].data[1] >= warn[7])
            document.getElementById('w8').setAttribute('fill','red');
    else if(option_c.series[0].data[1] <= warn_l[7])
            document.getElementById('w8').setAttribute('fill','red');
    else
            document.getElementById('w8').setAttribute('fill','green');
            
    if(option_c.series[0].data[0] >= warn[8])
            document.getElementById('w9').setAttribute('fill','red');
    else if(option_c.series[0].data[0] <= warn_l[8])
            document.getElementById('w9').setAttribute('fill','red');
    else
            document.getElementById('w9').setAttribute('fill','green');
}
