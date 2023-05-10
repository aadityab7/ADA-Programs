def coin_change_greedy(coins, amount):
    coins.sort(reverse=True)  # sort coins in descending order
    num_coins = 0  # number of coins used
    for coin in coins:
        if amount == 0:
            break
        if coin <= amount:
            num_coins += amount // coin
            amount %= coin
    if amount > 0:
        return -1  # solution not possible
    else:
        return num_coins
