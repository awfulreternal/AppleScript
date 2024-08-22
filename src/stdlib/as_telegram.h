#ifndef AS_TELEGRAM_H
#define AS_TELEGRAM_H

#include <string>
#include <vector>

/**
 * @class TelegramBot
 * @brief Класс для работы с Telegram Bot API.
 * 
 * Этот класс предоставляет методы для отправки сообщений и получения обновлений от Telegram.
 */
class TelegramBot {
public:
    /**
     * @brief Конструктор класса.
     * @param token Токен бота, полученный от BotFather в Telegram.
     */
    explicit TelegramBot(const std::string& token);

    /**
     * @brief Отправляет текстовое сообщение в указанный чат.
     * @param chatId Идентификатор чата, в который нужно отправить сообщение.
     * @param message Сообщение, которое будет отправлено.
     * @return true, если сообщение успешно отправлено, иначе false.
     */
    bool sendMessage(const std::string& chatId, const std::string& message);

    /**
     * @brief Получает обновления (новые сообщения) из Telegram.
     * @return Вектор строк, содержащий текст новых сообщений.
     */
    std::vector<std::string> getUpdates();

private:
    std::string token; ///< Токен для аутентификации в Telegram API.
    const std::string apiUrl; ///< URL для доступа к Telegram Bot API.

    /**
     * @brief Выполняет HTTP-запрос по указанному URL.
     * @param url URL, на который будет отправлен запрос.
     * @return Ответ на запрос в виде строки.
     */
    std::string performRequest(const std::string& url);
};

#endif // AS_TELEGRAM_H
