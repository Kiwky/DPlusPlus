``Discord events:``
```c++
  virtual void OnMessageCreated(const MessageCreateEventArgs &message);
  virtual void OnMessageDeleted(const MessageDeleteEventArgs &message);
```

`` Channel methods ``
```c++

  	Message GetMessage(const Snowflake &messageId);
    	std::vector<Message> GetMessages(int limit = 100);
    	Message SendMessage(const std::string &content, Embed *embed = nullptr);
    	void ModifyChannel(const std::string &name, const std::string &topic);
    	void DeleteMessageBulk(const std::vector<Message> &messages);
```

``Message methods``
```c++
	void ModifyMessage(Message &message);
	void DeleteMessage();
```
