<?xml version="1.0" encoding="utf-8"?>
<?AutomationStudio FileVersion="4.9"?>
<SwConfiguration CpuAddress="SL1" xmlns="http://br-automation.co.at/AS/SwConfiguration">
  <TaskClass Name="Cyclic#1">
    <Task Name="Test" Source="Test.prg" Memory="UserROM" Language="IEC" Debugging="true" />
  </TaskClass>
  <TaskClass Name="Cyclic#2" />
  <TaskClass Name="Cyclic#3" />
  <TaskClass Name="Cyclic#4" />
  <TaskClass Name="Cyclic#5" />
  <TaskClass Name="Cyclic#6" />
  <TaskClass Name="Cyclic#7" />
  <TaskClass Name="Cyclic#8" />
  <Libraries>
    <LibraryObject Name="AsIOTime" Source="Libraries._AS.AsIOTime.lby" Memory="UserROM" Language="binary" Debugging="true" />
    <LibraryObject Name="brsystem" Source="Libraries._AS.brsystem.lby" Memory="UserROM" Language="binary" Debugging="true" />
    <LibraryObject Name="MTLookUp" Source="Libraries.MTLookUp.lby" Memory="UserROM" Language="binary" Debugging="true" />
    <LibraryObject Name="runtime" Source="Libraries._AS.runtime.lby" Memory="UserROM" Language="binary" Debugging="true" />
    <LibraryObject Name="standard" Source="Libraries._AS.standard.lby" Memory="UserROM" Language="binary" Debugging="true" />
    <LibraryObject Name="sys_lib" Source="Libraries._AS.sys_lib.lby" Memory="UserROM" Language="binary" Debugging="true" />
    <LibraryObject Name="FileIO" Source="Libraries._AS.FileIO.lby" Memory="UserROM" Language="binary" Debugging="true" />
    <LibraryObject Name="Hammers" Source="Libraries.Loupe.Hammers.lby" Memory="UserROM" Language="AnsiC" Debugging="true" />
  </Libraries>
</SwConfiguration>