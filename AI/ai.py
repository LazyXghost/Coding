from utils import *

while(time.time() < starting_time + running_time):
    if(game_over()):
        start_game()


# while not game.crash:
#     #agent.epsilon is set to give randomness to actions
#     agent.epsilon = 80 - counter_games
    
#     #get old state
#     state_old = agent.get_state(game, player1, food1)
    
#     #perform random actions based on agent.epsilon, or  choose the action
#     if randint(0, 1) < agent.epsilon:
#         final_move = to_categorical(randint(0, 2), num_classes=3)
#     else:
#         # predict action based on the old state
#         prediction = agent.model.predict(state_old.reshape((1,11)))
#         final_move = to_categorical(np.argmax(prediction[0]), num_classes=3)[0]
        
#     #perform new move and get new state
#     player1.do_move(final_move, player1.x, player1.y, game, food1, agent)
#     state_new = agent.get_state(game, player1, food1)
    
#     #set treward for the new state
#     reward = agent.set_reward(player1, game.crash)
    
#     #train short memory base on the new action and state
#     agent.train_short_memory(state_old, final_move, reward, state_new, game.crash)
    
#     # store the new data into a long term memory
#     agent.remember(state_old, final_move, reward, state_new, game.crash)
#     record = get_record(game.score, record)


# xdotool getmouselocation
# https://snake.io/
# https://towardsdatascience.com/how-to-teach-an-ai-to-play-games-deep-reinforcement-learning-28f9b920440a