package com.brightideas.sayaku {
	

  import flash.external.ExtensionContext;
  //如果想要讓此類別可以發送及偵聽事件可以繼承EventDispatcher
  
  /**
	 * ...
	 * @author sayaku
	 */
  
  public class BrightIdeasWindowsNative
  {
    private var _ec:ExtensionContext;

    public function BrightIdeasWindowsNative()
    {
      _ec = ExtensionContext.createExtensionContext("com.brightideas.sayaku.BrightIdeasWindowsNative", "");
    }

    public function setMousePos(_x:int, _y:int):void
    {
        //調用原生C++的setMousePosition方法
       _ec.call('setMousePosition', _x, _y);

    }
  
    public function mouseClick():void
    {
        //調用原生C++的mouseClick方法＿
       _ec.call('mouseClick',0);

    }
	
	public function mouseDown():void
    {
        //調用原生C++的mouseDown方法＿
       _ec.call('mouseDown',0);

    }
	
	public function mouseUp():void
    {
        //調用原生C++的mouseUp方法＿
       _ec.call('mouseUp',0);

    }
	
	public function keyDown(vcode:int):void
    {
        //調用原生C++的keyDown方法＿
       _ec.call('keyDown',vcode);

    }
  
    public function dispose():void
    {
      _ec.dispose();
    }
  }
}