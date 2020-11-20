
# Graphical User Interfaces & Event-Based Programming


* Up to now: sequential programming, CLI (Command Line Interface)
* Most (modern) HCI (Human Computer Interaction) is done through a GUI
* Thin clients: browsers, cross-platform
* Thick clients: full programs compiled for a particular system
* Event based programming: human interactions are handled by a windowing system (or browser); human interactions trigger *events* which are handled by *your* code
* Instead of specifying what happens in a program, you specify what happens when an event occurs

## Brief, Uninteresting History

* 1973 Xerox (Alto)
* 1983 Apple's Lisa
* Macintosh (IIgs) 1986
* Microsoft Windows 1.0 (1985)
* 90s user interfaces blew up
* 2010s: mobile devices and interfaces
* Beyond: Kinect/gesture, VR/AR/XR interfaces

## Frameworks

* C: GTK
* C++: GTK+, Qt, wxWidgets, etc.
* Java: AWT, Swing, JavaFX
* Swift

## GUI Components

1. Windowing System
    * Handles low-level functionality: hardware interaction (keyboard, mouse) interaction
    * Graphics rendering
2. Windowing Manager
    * Handles interaction of applications, windows and *widgets*
    * Controls the flow of an application by *registering* and handling *events*
    * An event is an action that is initiated outside the scope of a program but that is handled by the program
3. Widgets
    * Are generic GUI elements
    * They may be visible or invisible
    * They may be interactive or static
    * Examples:
        * Buttons
        * Sliders
        * Label
        * Text boxes
        * Drop Down menus
        * Radio boxes
        * Check box
        * Images, icons
        * Menu
        * Windows
        * popups, prompts, etc.
        * Layouts: grids, rows, columns

## Event-Based Programming

* The program (window manager) waits for actions/events and messages/delegates actions to handlers through an infinite *poll loop*
* User-centric: there are many ways to accomplish the same thing
* and: there may or may not be a sequential flow of control
* UX: User Experience: good user interfaces will provide good feedback, good instruction/direction to human users and discourage bad behavior
* Modal behavior: at any point in the program, some subset of actions may be prevented or the user may only be able to "see" a small set of them
* Asynchronicity: User interfaces should not "block" a program; with an asynchronous program, you have the capability of continuing your interaction with the GUI
* Demo

## Events

* Events are asynchronous: there may be thousands per second, there may or may not be a *sequential* order to them
    * Clicking a widget
    * Mouse: move, mouse over, out, down, up, etc.
    * hover
    * Drag, drop, etc.
    * Keyboard events: key up key down, etc. Key combinations
* Event registration: with a particular event and a particular widget you can *register* a *handler* for that event
* Usually done via a "callback"

## Implementing GUIs

1. You need a way to create widgets
2. You need a way to specify a layout of widgets
3. You need a way to register events

## GTK Demo

`ssh -Y login@cse.unl.edu`


```

JavaFX:  
https://docs.oracle.com/javafx/2/get_started/hello_world.htm
FXML:  
https://javafxpedia.com/en/tutorial/1580/fxml-and-controllers
JavaFX Scene Builder:  
https://javafxpedia.com/en/tutorial/5445/scene-builder

App Studio:  
https://developer.android.com/studio/
Hello World:  
https://developer.android.com/codelabs/android-training-hello-world#0

















```
