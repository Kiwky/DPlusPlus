``Discord events:``
```c++
  virtual void OnMessageCreated(const MessageCreateEventArgs &message);
  virtual void OnMessageDeleted(const MessageDeleteEventArgs &message);
```

``Channel methods``
```c++
  	Message GetMessage(const Snowflake &messageId);
  	static Message GetMessage(const Snowflake &channelId, const Snowflake &messageId);
	  
    	std::vector<Message> GetMessages(int limit = 100);
	static std::vector<Message> GetMessages(const Snowflake &channelId, int limit = 100);
	  
    	Message SendMessage(const std::string &content, Embed *embed = nullptr);
	static Message SendMessage(const Snowflake &channelId, const std::string &content, Embed *embed = nullptr);
	  
    	void ModifyChannel(const std::string &name, const std::string &topic);
	static void ModifyChannel(const Snowflake &channelId, const std::string &name, const std::string &topic);
	 
    	void DeleteMessageBulk(const std::vector<Message> &messages);
	static void DeleteMessageBulk(const Snowflake &channelId, const std::vector<Message> &messages);
```

``Message methods``
``c++
	void ModifyMessage(Message &message);
	static void ModifyMessage(const Snowflake &channelId, const Snowflake &messageId, Message &message);

	void DeleteMessage();
	static void DeleteMessage(const Snowflake &channelId, const Snowflake &messageId);

``
