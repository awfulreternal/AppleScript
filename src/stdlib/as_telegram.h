#ifndef AS_TELEGRAM_H
#define AS_TELEGRAM_H

#include <string>
#include <vector>

// Класс для работы с Telegram API
class TelegramBot {
public:
    // Конструктор, принимающий токен бота
    explicit TelegramBot(const std::string& token);

    // Метод для отправки текстового сообщения в указанный чат
    bool sendMessage(const std::string& chatId, const std::string& message);

    // Метод для получения обновлений (новых сообщений) из Telegram
    std::vector<std::string> getUpdates();

private:
    std::string token; // Токен для аутентификации в Telegram API
    const std::string apiUrl; // URL для доступа к API Telegram

    // Метод для выполнения HTTP-запроса по указанному URL
    std::string performRequest(const std::string& url);
};

#endif // AS_TELEGRAM_H
