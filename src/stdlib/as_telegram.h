#ifndef AS_TELEGRAM_H
#define AS_TELEGRAM_H

#include <string>
#include <vector>

// Класс для работы с Telegram API
class TelegramBot {
public:
    // Конструктор
    TelegramBot(const std::string& token);

    // Метод для отправки текстового сообщения
    bool sendMessage(const std::string& chatId, const std::string& message);

    // Метод для получения обновлений (новых сообщений)
    std::vector<std::string> getUpdates();

private:
    std::string token;
    const std::string apiUrl;

    // Метод для выполнения HTTP-запроса
    std::string performRequest(const std::string& url);
};

#endif // AS_TELEGRAM_H
