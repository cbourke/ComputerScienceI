# Hack 14.0 - Distributed Computing & Vibe Coding
**[School of Computing](https://computing.unl.edu/)**  
**[College of Engineering](https://engineering.unl.edu/)**  
**[University of Nebraska-Lincoln](https://unl.edu)**  
**[University of Nebraska-Omaha](https://http://unomaha.edu/)**  

# Introduction

Hack session activities are small weekly programming assignments
intended to get you started on full programming assignments. You may
complete the hack on your own, but you are *highly encouraged* to work
with another student and form a hack pair. Groups larger than 2 are not
allowed. However, you may discuss the problems *at a high level* with
other students or groups. You may not share code directly outside your
pair.

If you choose to form a Hack Pair, you *must*:

1.  Both join a hack pair on Canvas (go to People then Groups)

2.  You must both work on the hack equally; it must be an equal effort
    by both partners. Do not undermine your partner's learning
    opportunity and do not undermine your own by allowing one parter to
    do all the work.

3.  You may both turn in a copy, but only one will be graded (generally
    the one whose last name comes first alphabetically).

## Rubric

This assignment will be graded slightly differently than previous hacks.
First, you must submit all of the items below (see [Submission](#submission)) or no credit.
If you won a game you will get 25/25.  If you were not able to win a game
but it is clear from your submission material that you put forth a full
effort you will get 20/25.  

# Problem Statement

Recall that *distributed computing* involves multiple machines working together,
typically communicating via a network.  The client-server model is one way of
doing this; a client makes requests to a server and the server responds.  In this
hack, you will design and implement a client that plays a game with our server.
Your client will communicate with our server using the HyperText Transfer
Protocol (HTTP) that is the basis of most web communication.  Messages back
and forth will use JSON formatting.

## Battleship

Battleship is a game played on a 10 x 10 grid in which 5 ships of various lengths
are placed and hidden.

| Ship Type  | Unit Length |
|------------|-------------|
| Destroyer  | 2           |
| Submarine  | 3           |
| Cruiser    | 3           |
| Battleship | 4           |
| Carrier    | 5           |

In our version, you will only play against the enemy's board (you will not
have your own ships).  You play by guessing (firing)
a shot at an $(x, y)$-coordinate on the board (both dimensions are
in the range 0-9 inclusive).  Each valid fire results in a hit or a
miss.  Hit all of a ship's units and you sink it.  You win when all of
the ships have been sunk and your score is still positive.  You lose
if you have run out of points without sinking all of the ships.  Scoring
is based on the following: each fire (guess) costs you two points.  
An invalid fire will cost you 2 points and a fire at a coordinate
where a fire was already shot costs you one point.  You start out
with 120 points.

## How to Play

### Starting a Game

To play a game on the server, you need to first start a game.  You can
do this by making an HTTP `GET` or `POST` request to the following URL:

<http://csce.unl.edu:8080/Battleship/NewGame?login=FOO>

where `FOO` is replaced with your login ID.  The server will setup a brand
new game and respond with a JSON formatted response.  An example of the response:

```json
{
  "login":"cbourke",
  "game_id":"9ebd7200"
}
```

The `game_id` is a unique identifier for your game (a randomly
generated hexadecimal).  You'll need to keep track of this game ID
to make moves.

### Making a Move

A move will need to be communicated to the server in a similar manner.  
You will `GET` or `POST` a request describing a move
(as a parameter named `move`) to the following URL:

<http://csce.unl.edu:8080/Battleship/Move>

The request is expected to be in the following JSON format.

```json
{
  "game_id" : "9ebd7200",
  "login": "cbourke",
  "x": 1,
  "y": 8
}
```

which shoots at grid point $(1, 8)$.  Of course, each value should be
replaced by your `game_id` and your `login`, and your actual guess.  
Depending on the result, you should get back a JSON formatted response
such as the following.

```json
{
  "game_id":"e2f3e051",
  "login":"cbourke",
  "result":"HIT",
  "x":1,
  "y":8,
  "cost":1,
  "score":40,
  "game_status":"playing",
  "message":"WARNING: you've already made this move"
}
```

Some of the key-value pairs are self-explanatory.  For the others, here
are the following possible values:


* `result` -- will either be `HIT`, `MISS` or `ERROR`.  In the event of
  an error, the message will contain (hopefully) a helpful message
	describing the error
* `cost` -- this is the amount that the move you just made cost you
* `score` -- this is the score of the game after the move you just made
* `game_status` -- will either be `playing`, `won`, or
	`lost` depending on your score and how many ships you've sunk
* `message` -- may contain some message regarding your last move
	(another example: `You sunk my Battleship!`)

# Vibe Coding the Client

No, we're not expecting you to know enough network and distributed computing
programming to be able to do this on your own.  Instead, you will be leveraging
your accumulated knowledge and use an LLM/AI (ChatGPT recommended) to help you
with the development.

You goal is to write code to win a game.  This could be:
* Recommended: a text-based interface program that allows you to enter shots
  and prints a grid of the game status until (then you play it until you win a game)
* A program that automatically plays the game until it wins
* A graphical program that allows you to click grid squares to play the game

You can use the LLM/AI in any manner that you choose, but recall our best
practices.  

<a id="submission"></a>
## Submission

* Submit all the code that the LLM generated and/or that you wrote.
* Submit a `readme.md` file that contains:
  * The ID of your winning game and your winning score, OR
  * If you were not able to win a game, provide an explanation of why;
    how long did you spend on this?  Where did you get stuck?  What
    did you try to get unstuck?  
  * A a few paragraphs of your experience: was it fun?  Was it frustrating?
    What do you think of the power of the LLM/AI?  What do you think of the
    quality of code it produced? (Do *NOT* use ChatGPT to write this for
    you; we want your honest personal experience).
  * A complete sequence of the prompts you used to get a working solution.
    You can get ChatGPT to give this to you using the prompt
    `Give me the sequence of prompts I've given you since the start`
