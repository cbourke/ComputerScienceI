
# Computer Science I
## Graphical User Interfaces & Event-Based Programming
### Fall 2021

# Introduction

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
* Android Studio (WYSIWYG): https://developer.android.com/studio/
* iOS: Swift

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
      * Text boxes (static)
      * Text boxes for input
      * Sliders
      * Labels
      * Menus
      * Drop down menus
      * "canvas"
      * date or time selector
      * color selector
      * Windows
      * images, icons, etc.
      * Popups, prompts, etc
      * Layouts: grid layouts, rows, columns

## Event-Based Programming

* The program (window manager) waits for actions/events and messages/delegates actions to handlers through an infinite *poll loop*
* User-centric: there are many ways to accomplish the same thing
* and: there may or may not be a sequential flow of control
* Good UX: User Experience:
  * Good interfaces will *guide* a user to the "correct" actions
  * Good interfaces will dissuade or prevent "bad" actions
* Modal behavior: at any point in the program, some subset of actions may be prevented or the user may only be able to "see" a small set of them
* Asynchronicity: User interfaces should not "block" a program; with an asynchronous program, you have the capability of continuing your interaction with the GUI

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

```text









```
